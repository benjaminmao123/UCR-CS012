#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet() : IntList()
{
    return;
}

SortedSet::SortedSet(const SortedSet &set) : IntList(set)
{
    return;
}

SortedSet::SortedSet(const IntList &list) : IntList(list)
{
    remove_duplicates();
    selection_sort();
    return;
}

SortedSet::~SortedSet()
{
    return;
}
//This function returns true if the value in data is a member of the set, otherwise false.
bool SortedSet::in(int data)const
{
    for (IntNode *i = head; i != 0; i = i->next)
    {
        if (i->data == data)
        {
            return true;
        }
    }
    
    return false;
}
//This function returns a SortedSet object that is the union of 2 SortedSet objects, the left and right operands of this binary operator. 
//A union of 2 sets is a set that consists of all of the distinct elements of both sets combined. 
//That is, all of the values in both sets, minus any duplicates.
const SortedSet SortedSet::operator|(const SortedSet& rhs)const
{
    SortedSet result;
    for (IntNode *i = head; i != 0; i = i->next)
    {
        result.add(i->data);
    }
    for (IntNode *j = rhs.head; j != 0; j = j->next)
    {
        result.add(j->data);
    }
    
    return result;
}
//This function returns a SortedSet object that is the intersection of 2 SortedSet objects, the left and right operands of this binary operator. 
//An intersection of 2 sets is a set of all elements that are in both sets. 
//That is, all of the values that are in both the left operand and the right operand.
const SortedSet SortedSet::operator&(const SortedSet& rhs)const
{
    SortedSet set;
    
    for (IntNode *i = head; i != 0; i = i->next)
    {
        if (rhs.in(i->data))
        {
            set.add(i->data);
        }
    }
    
    return set;
}
void SortedSet::add(int data)
{
    if (!in(data))
    {
        IntList::insert_ordered(data);
    }
    
    return;
}
void SortedSet::push_front(int data)
{
    add(data);
    
    return;
}
void SortedSet::push_back(int data)
{
    add(data);
    
    return;
}
void SortedSet::insert_ordered(int data)
{
    add(data);
    
    return;
}
//This function is the union-assign operator function. 
//It returns a union of the left and right operands, but also sets the left operand's value to be that union as well. 
//The return type is a non-const reference to a SortedSet.
 SortedSet& SortedSet::operator|=(const SortedSet& rhs)
{
    *this = *this | rhs; 
    
    return *this;
}
//This function is the intersection-assign operator function. 
//It returns an intersection of the left and right operands, but also sets the left operand's value to be that intersection as well.
//The return type is a non-const reference to a SortedSet.
 SortedSet& SortedSet::operator&=(const SortedSet& rhs)
{
    *this = *this & rhs;
    
    return *this;
}