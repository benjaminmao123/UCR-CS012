#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Message 
{
protected:
    unsigned id;
    vector<Message *> childList;
	string author;
	string subject;
	string body;
    
public:
    Message();
    
	Message(const string &, const string &sbjct, const string &body, unsigned id);

    virtual ~Message();

	void print(unsigned indentation) const;

	unsigned getID() const;

	void addChild(Message *child);

	const string & getSubject() const;
    
	virtual bool isReply() const = 0;

    virtual string toFormattedString() const = 0;
};
#endif