#include "Message.h"
#include "Topic.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

Topic::Topic()
{
	author = "";
	subject = "";
	body = "";
	id = 0;
}

Topic::Topic(const string &athr, const string &sbjct, const string &body, unsigned id)
{
	author = athr;
	subject = sbjct;
	this->body = body;
	this->id = id;
}

bool Topic::isReply() const
{
	return false;
}

string Topic::toFormattedString() const
{
	string topicFormatted;

	topicFormatted = string("<begin_topic>\n:id: ") + to_string(id) + "\n:subject: " + subject + "\n:from: " + author;

	if (childList.size() != 0)
	{
		topicFormatted = topicFormatted + "\n:children: ";
		for (unsigned int i = 0; i < childList.size() - 1; ++i)
		{
			topicFormatted = topicFormatted + to_string(childList.at(i)->getID()) + " ";
		}
		topicFormatted = topicFormatted + to_string(childList.at(childList.size() - 1)->getID());
	}

	topicFormatted = topicFormatted + "\n:body: " + body + "\n<end>\n";

	return topicFormatted;
}


