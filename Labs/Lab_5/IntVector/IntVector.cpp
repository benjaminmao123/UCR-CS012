#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    data = 0;
    
    return;
}

//Sets both the size and capacity of the IntVector to the value of the parameter passed in and dynamically allocates an array of that size as well. 
//This function should initialize all elements of the array to the value of the 2nd parameter.
IntVector::IntVector(unsigned size, int value)
{
    sz = size;
    cap = size;
    
    data = new int[cap];
    
    for (unsigned int i = 0; i < size; ++i)
    {
        data[i] = value;
    }
    
    return;
}

IntVector::~IntVector()
{
    delete[] data;
    
    return;
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if (sz == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    return false;
}

//This function will return the value stored in the element at the passed in index position. Your function should throw an outofrange exception if an invalid index is passed in. 
//An invalid index is an index greater than or equal to the size.
const int & IntVector::at(unsigned index) const
{
    if (index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else 
    {
        return data[index];
    }
}

const int & IntVector::front() const
{
    return data[0];
}

const int & IntVector::back() const
{
    return data[sz-1];
}