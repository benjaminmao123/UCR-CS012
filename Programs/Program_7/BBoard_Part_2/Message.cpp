#include "Message.h"
#include "Reply.h"

#include <iostream>
#include <string>

using namespace std;

Message::Message()
{
	author = "";
	subject = "";
	body = "";
	id = 0;
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id) 
{
	author = athr;
	subject = sbjct;
	this->body = body;
	this->id = id;
}

Message::~Message()
{

}

void Message::print(unsigned indentation) const
{
	if (isReply())
	{
		cout << endl;
	}

	for (unsigned int i = 0; i < indentation; ++i)
	{
		cout << "  ";
	}

	cout << "Message #" << id << ": " << subject << endl;

	for (unsigned int i = 0; i < indentation; ++i)
	{
		cout << "  ";
	}

	cout << "from " << author << ": ";

	for (unsigned int i = 0; i < body.length(); ++i)
	{
		if (body.at(i) == '\n')
		{
			cout << endl;
			for (unsigned int j = 0; j < indentation; ++j)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << body.at(i);
		}
	}

	cout << endl;

	for (unsigned int i = 0; i < childList.size(); ++i)
	{
		childList.at(i)->print(indentation + 1);
	}
}

unsigned Message::getID() const
{
	return id;
}

void Message::addChild(Message *child)
{
	childList.push_back(child);
}

const string & Message::getSubject() const
{
	return subject;
}