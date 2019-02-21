#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "BBoard.h"
#include "User.h"
#include "Message.h"

using namespace std;

BBoard::BBoard():
title("board")
 {}

BBoard::BBoard(const string &boardName):
title(boardName)
{}

bool BBoard::loadUsers(const string &fileName)
{
    ifstream inFS;
    string uname, pass;
    
    inFS.open(fileName.c_str());
    
    if(!inFS.is_open())
    {
        return false;
    }
    
    while(inFS >> uname >> pass)
    {
        userList.push_back(User(uname, pass));
    }
    
    return true;
}

bool BBoard::login()
{
    string userName;
    string passWord;
    
    cout << "Welcome to " << title << endl;
    
    while(userName != "Q" && userName != "q")
    {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> userName;
        cout << endl;
    
        if(userName == "Q" || userName == "q")
        {
            cout << "Bye!" << endl;
            return false;
        }
    
        cout << "Enter your password: ";
        cin >> passWord;
        cout << endl;
    
        if(passWord == "Q" || passWord == "q")
        {
            cout << "Bye!" << endl;
            return false;
        }
        
        if(userExists(userName, passWord) == true)
        {
            cout << "Welcome back " << userName << "!" << endl;
            cout << endl;
            currentUser = User(userName, passWord);
            
            return true;
        }
        else
        {
            cout << "Invalid Username or Password!" << endl;
            cout << endl;
        }
    }
    
    return false;
}

void BBoard::run()
{
    string userInput;
        
    while(userInput != "Q" && userInput != "q")
    {
        cout << "Menu" << endl;
        cout << "- Display Messages ('D' or 'd')" << endl;
        cout << "- Add New Message ('N' or 'n')" << endl;
        cout << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: "; 
                
        cin >> userInput;
        cout << endl;
        
        if(userInput == "Q" || userInput == "q")
        {
            cout << "Bye!" << endl;
            return;
        }
        if(userInput == "D" || userInput == "d")
        {
            display();
        }
        if(userInput == "N" || userInput == "n")
        {
            addMessage();
        }
    }
}

void BBoard::display() const
{
    int count = 1;
    
    if(messageList.size() == 0)
    {
        cout << "Nothing to Display." << endl;
        cout << endl;
        return;
    }
    
    for(unsigned int i = 0; i < messageList.size(); ++i)
    {
        cout << "---------------------------------------------------------" << endl;
        cout << "Message #" << count << ": ";
        messageList.at(i).display();
        ++count;
    }
    
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

void BBoard::addMessage()
{
    string userSubject;
    string userBody;
    
    cin.ignore();
    
    cout << "Enter Subject: ";
    getline(cin, userSubject);
    
    cout << endl;
    
    cout << "Enter Body: ";
    getline(cin, userBody);
    
    cout << endl;
    
    
    messageList.push_back(Message(currentUser.getUsername(), userSubject, userBody));
    
    cout << "Message Recorded!" << endl;
    cout << endl;
}

bool BBoard::userExists(const string &userName, const string &passWord) const
{
    for(unsigned int i = 0; i < userList.size(); ++i)
    {
        
        if(userList.at(i).check(userName, passWord))
        {
            return true;
        }
    }
    
    return false;
}
