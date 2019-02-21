#ifndef SORTEDSET_H
#define SORTEDSET_H
#include <iostream>
#include "IntList.h"

using namespace std;

class SortedSet : public IntList
{
    public:
        SortedSet();
        SortedSet(const SortedSet &set);
        SortedSet(const IntList &list);
        ~SortedSet();
        bool in(int data)const;
       const SortedSet operator|(const SortedSet& rhs)const;
       const SortedSet  operator&(const SortedSet& rhs)const;
        void add(int data);
        void push_front(int data);
        void push_back(int data);
        void insert_ordered(int data);
       SortedSet& operator|=(const SortedSet& rhs);
        SortedSet& operator&=(const SortedSet& rhs);
};
#endif