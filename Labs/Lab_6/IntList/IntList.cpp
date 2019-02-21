#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList()
{
    head = 0;
    tail = 0;
}

IntList::~IntList()
{
    IntNode *temp;
    
    while (head != 0)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    
    return;
}

void IntList::display() const
{
    if (head == 0)
    {
        return;
    }
    else
    {
        IntNode *temp = head->next;
        cout << head->data;
        while (temp != 0)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
    
    return;
}

void IntList::push_front(int value)
{
    if (head == 0)
    {
        head = new IntNode(value);
        tail = head;
    }
    else
    {
        IntNode *temp = new IntNode(value);
        temp->next = head;
        head = temp;
    }
    
    return;
}

void IntList::pop_front()
{
	if (head == 0)
	{
	    return;
	}
	else if (head != 0)
	{
		IntNode *temp = head->next;
		delete head;
		head = temp;
	}
    
    return;
}

bool IntList::empty() const
{
    if (head == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    return false;
}