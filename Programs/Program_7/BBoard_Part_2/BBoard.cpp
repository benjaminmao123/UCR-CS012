#include "BBoard.h"
#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

BBoard::BBoard() : title("board"), currentUser(nullptr)
{

}

BBoard::BBoard(const string &boardName) : title(boardName)
{

}

BBoard::~BBoard()
{
	for (unsigned int i = 0; i < messageList.size(); ++i)
	{
		delete messageList.at(i);
	}
}

bool BBoard::loadUsers(const string &fileName)
{
    ifstream inFS;
    string uname, pass;
    
    inFS.open(fileName.c_str());
    
    if (!inFS.is_open())
    {
        return false;
    }
    
    inFS >> uname;
    
    while (uname != "end")
    {
        inFS >> pass;
        
        userList.push_back(User(uname, pass));
        
        inFS >> uname;
    }
    
	inFS.close();

    return true;
}

void BBoard::login()
{
    string username;
    string password;
    
	cout << "Welcome to " << title << endl;
	
	while (getUser(username, password) == nullptr)
	{
		cout << "Enter your username ('Q' or 'q' to quit): ";
		cin >> username;

		if (username == "Q" || username == "q")
		{
			cout << "Bye!" << endl;
			exit(0);
		}
		else
		{
			cout << "Enter your password: ";
			cin >> password;
			if (getUser(username, password) == nullptr)
			{
				cout << "Invalid Username or Password!" << endl << endl;
			}
			else
			{
				cout << endl;
				currentUser = getUser(username, password);
			}
		}
	}
}

void BBoard::run()
{
	if (currentUser == nullptr)
	{
		return;
	}
	else
	{
		cout << "Welcome back " << currentUser->getUsername() << "!" << endl << endl;
	}

	string userInput;

	while (userInput != "Q" && userInput != "q")
	{
		cout << "Menu" << endl;
		cout << "- Display Messages ('D' or 'd')" << endl;
		cout << "- Add New Topic ('N' or 'n')" << endl;
		cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
		cout << "- Quit ('Q' or 'q')" << endl;
		cout << "Choose an action: ";

		cin >> userInput;

		if (userInput == "Q" || userInput == "q")
		{
			cout << "Bye!" << endl;
			currentUser = nullptr;
			return;
		}
		else if (userInput == "D" || userInput == "d")
		{
			display();
		}
		else if (userInput == "N" || userInput == "n")
		{
			addTopic();
		}
		else if (userInput == "R" || userInput == "r")
		{
			addReply();
		}
	}	
}

void BBoard::display() const
{   
    if (messageList.size() == 0)
    {
		cout << endl << "Nothing to Display." << endl << endl;
        return;
    }
    
	cout << endl;

    for (unsigned int i = 0; i < messageList.size(); ++i)
    {
		if (!messageList.at(i)->isReply())
		{
			cout << "---------------------------------------------------------" << endl;
			messageList.at(i)->print(0);
		}
    }
	
	cout << "---------------------------------------------------------" << endl << endl;
}

bool BBoard::loadMessages(const string &datafile)
{
	ifstream ifs;

	ifs.open(datafile.c_str());

	if (!ifs.is_open())
	{
		return false;
	}

	string author, subject, body, childID, temp, tag, stringID, tempBody, buffer, spaces, tempSubject;
	unsigned id = 0;
	int numMessages;
	bool isTopic = false;
	bool isBody = false;

	ifs >> numMessages;
	vector<string> tempVec;

	while (getline(ifs, temp))
	{

		istringstream iss(temp);
		iss >> tag;

		if (tag == "<begin_topic>")
		{
			isTopic = true;
		}
		else if (tag == "<begin_reply>")
		{
			isTopic = false;
		}
		else if (tag == ":id:")
		{
			iss >> id;
		}
		else if (tag == ":subject:")
		{
			getline(iss >> ws, subject);
			//iss >> tempSubject;
			//if (tempSubject != "Re:")
			//{
			//	getline(iss, subject);
			//	subject = tempSubject + subject;
			//}
		}
		else if (tag == ":from:")
		{
			getline(iss >> ws, author);
		}
		else if (tag == ":children:")
		{
			getline(iss >> ws, childID);
		}
		else if (tag == ":body:")
		{
			isBody = true;
			getline(iss >> ws, tempBody);
			body = body + tempBody + "\n";
		}
		else if (tag != "<end>" && isBody == true)
		{
			if (getline(iss, tempBody))
			{
				body = body + tag + tempBody + "\n";
			}
			else
			{
				body = body + tag + "\n";
			}
		}
		else if (tag == "<end>")
		{
			body.erase(body.size() - 1);
			
			if (isTopic == true)
			{
				messageList.push_back(new Topic(author, subject, body, id));
				tempVec.push_back(childID);
				childID = "";
				body = "";
			}
			else if (isTopic == false)
			{
				messageList.push_back(new Reply(author, subject, body, id));
				tempVec.push_back(childID);
				childID = "";
				body = "";
			}
		}
	}

	ifs.close();

	unsigned ids;
	for (unsigned int i = 0; i < tempVec.size(); ++i)
	{
		istringstream iss(tempVec.at(i));

		while (iss >> ids)
		{
			if (tempVec.at(i) == "")
			{
				break;
			}

			messageList.at(i)->addChild(messageList.at(ids - 1));
		}
	}

    return true;
}

bool BBoard::saveMessages(const string &datafile)
{
	ofstream outFS;
	
	outFS.open(datafile.c_str());

	if (!outFS.is_open())
	{
		return false;
	}

	outFS << messageList.size() << endl;

	for (unsigned int i = 0; i < messageList.size(); ++i)
	{
		outFS << messageList.at(i)->toFormattedString();
	}

	outFS.close();

	return true;
}

const User * BBoard::getUser(const string &name, const string &pw) const
{
	for (unsigned int i = 0; i < userList.size(); ++i)
	{
		if (userList.at(i).check(name, pw))
		{
			return &userList.at(i);
		}
	}

	return 0;
}

void BBoard::addTopic()
{
	string subject, body;
	string temp = " ";
	string author = currentUser->getUsername();
	unsigned id = messageList.size() + 1;

	cin.ignore(1000, '\n');

	cout << "Enter Subject: ";
	getline(cin, subject);

	cout << "Enter Body: ";
	while (temp != "")
	{
		getline(cin, temp);
		body = body + temp + '\n';
	}

	cout << endl;

	body.erase(body.size() - 2, 2);

	Topic *topic = new Topic(author, subject, body, id);
	messageList.push_back(topic);
}

void BBoard::addReply()
{
	int id;
	string body, subject, author;
	author = currentUser->getUsername();

	if (messageList.size() == 0)
	{
		return;
	}

	cin.ignore(1000, '\n');

	while (true)
	{
		cout << "Enter Message ID(-1 for Menu): ";
		cin >> id;
		
		if (id == -1)
		{
			return;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Message ID!!" << endl << endl;
		}
		else if (messageList.size() > 1)
		{
			if (id < 1 || id > static_cast<int>(messageList.size()))
			{
				cout << "Invalid Message ID!!" << endl << endl;
			}
			else
			{
				break;
			}
		}
		else if (messageList.size() < 2)
		{
			if (id > 2 || id < 1)
			{
				cout << "Invalid Message ID!!" << endl << endl;
			}
			else
			{
				break;
			}
		}
	}

	subject = "Re: " + messageList.at(id - 1)->getSubject();

	cin.ignore(1000, '\n');

	string tempBody = " ";

	cout << "Enter Body: ";
	
	while (tempBody != "")
	{
		getline(cin, tempBody);
		body = body + tempBody + '\n';
	}

	body.erase(body.size() - 2, 2);

	unsigned ids = messageList.size() + 1;

	Reply *reply = new Reply(author, subject, body, ids);
	messageList.push_back(reply);
	messageList.at(id - 1)->addChild(reply);
}