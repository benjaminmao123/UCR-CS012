#include <iostream>
#include "IntList.h"
#include <istream>
using namespace std;

IntList::IntList()
{
    head = 0;
    tail = 0;
    
    return;
}

IntList::~IntList()
{
    IntNode *temp;
    
    while (head != 0)
    {
        temp = head -> next;
       
        delete head;
         head = temp;
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
   
}
//the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy)
{
    head = 0;
    tail = 0;
    
    for (IntNode *i = cpy.head; i != 0; i = i->next)
    {
        this->push_back(i->data);
    }
    
    
    return;
}

IntList & IntList::operator=(const IntList &rhs)
{
    if (this != &rhs)
    {
        clear();
        for (IntNode *i = rhs.head; i != 0; i = i->next)
        {
            this->push_back(i->data);
        }
    }
    
    return *this;
}
//Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value)
{
    if (empty())
    {
        head = tail = new IntNode(value);
        return;
    }
    
    IntNode *temp = new IntNode(value);
    tail->next = temp;
    tail = temp;
    
    return;
}
//Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.
void IntList::clear()
{
    while (head != 0)
    {
        pop_front();
    }
    
    return;
}
//Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
void IntList::selection_sort()
{
    if (empty())
    {
        return;
    }
   IntNode * min = head;
    
    for (IntNode *i = head; i != 0; i = i->next)
    {
       // int min = i->data;
         min = i;
        for (IntNode *j = i->next; j != 0; j = j->next)
        {
            if (min ->data > j->data)
            {
                min = j;
                // min = j->data;
                // j->data = i->data;
                // i->data = min;
            }
        }
        swap(i->data, min->data);
    }
    
    return;
}
//Inserts a data value (within a new node) in an ordered list. 
//Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.)
//This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location.
//This function may NOT ever sort the list.
void IntList::insert_ordered(int value)
{
    if (head == 0)
    {
        push_front(value);
    }
    else if (value <= head->data)
    {
        push_front(value);
    }
    else if (value >= tail->data)
    {
        push_back(value);
    }
    else
    {
        IntNode *temp = new IntNode(value);
		IntNode *prev = 0;
		IntNode *curr = head;

		while (curr != 0)
		{
		    if (curr->data >= value)
		    {
		        break;
		    }
		    else
		    {
		       prev = curr;
		   
		        curr = curr->next;
		    }
		}
    
        temp->next = curr;
        prev->next = temp;
    }
}




void IntList::remove_duplicates()
{
    IntNode* prev = head;
    for (IntNode *i = head; i != 0; i = i->next)
    {
        prev = i;
        
        for (IntNode* j = i->next; j != 0; j = j->next)
        {
            if (i->data == j->data)
            {
                if (j == tail)
                {
                    tail = prev;
                }
                
                prev->next = j->next;
                delete j;
            }
            else
            {
                prev = prev->next;
            }
        }
    }
    
    return;
}
//A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. 
//This function does NOT send to the stream a newline or space at the end.
ostream & operator<<(ostream &out, const IntList &rhs)
{
    if (rhs.empty())
    {
        return out;
    }
    else if (rhs.head == rhs.tail)
    {
        out << rhs.head->data;
    }
    else
    {
        IntNode *i;
        for (i = rhs.head; i != rhs.tail; i = i->next)
        {
            out << i->data << " ";
        }
        
        i = rhs.tail;
        out << i->data;
        
    }
    
    return out;
}