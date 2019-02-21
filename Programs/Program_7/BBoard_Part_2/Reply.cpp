#include "Message.h"
#include "Reply.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

Reply::Reply()
{
	author = "";
	subject = "";
	body = "";
	id = 0;
}

Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id)
{
	author = athr;
	subject = sbjct;
	this->body = body;
	this->id = id;
}

bool Reply::isReply() const
{
	return true;
}

string Reply::toFormattedString() const
{
	string replyFormatted;

	replyFormatted = string("<begin_reply>\n:id: ") + to_string(id) + "\n:subject: " + subject + "\n:from: " + author;

	if (childList.size() != 0)
	{
		replyFormatted = replyFormatted + "\n:children: ";
		for (unsigned int i = 0; i < childList.size() - 1; ++i)
		{
			replyFormatted = replyFormatted + to_string(childList.at(i)->getID()) + " ";
		}
		replyFormatted = replyFormatted + to_string(childList.at(childList.size() - 1)->getID());
	}

	replyFormatted = replyFormatted + "\n:body: " + body + "\n<end>\n";

	return replyFormatted;
}

