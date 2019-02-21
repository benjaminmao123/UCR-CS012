#include <iostream>
#include <vector>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

int main()
{
    unsigned int userIndex;
    int userInput;
    unsigned size;
    int value;
    unsigned n;

    cout << "Input size of vector: ";
    cin >> size;
    cout << endl;
    cout << "Input value for array elements: ";
    cin >> value;
    cout << endl;
    IntVector x(size, value);
    cout << "Values in array are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    cout << "Size: " << x.size() << endl;
    cout << "Capacity: " << x.capacity() << endl;
    cout << "Empty? " << x.empty() << endl;  
    cout << "Value of first element: " << x.front() << endl;
    cout << "Value of last element: " << x.back() << endl;
    
    cout << "---------------------" << endl;
    
    cout << "Checking insert function..." << endl;
    cout << "Values in array before insert function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    cout << "Value to insert: ";
    cin >> userInput;
    cout << endl;
    cout << "Enter index: ";
    cin >> userIndex;
    cout << endl;
    x.insert(userIndex, userInput);
    cout << "Values in array after insert function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    
    cout << "---------------------" << endl;
    
    cout << "Checking erase function..." << endl;
    cout << "Values in array before erase function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    cout << "Enter index: ";
    cin >> userIndex;
    cout << endl;
    x.erase(userIndex);
    cout << "Values in array after erase function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    
    cout << "---------------------" << endl;
    
    cout << "Checking push_back function..." << endl;
    cout << "Values in array before push_back function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    cout << "Size before push_back function: " << x.size() << endl;
    cout << "Enter value to push back into array: ";
    cin >> value;
    cout << endl;
    x.push_back(value);
    cout << "Values in array after push_back function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    cout << "Size after push_back function: " << x.size() << endl;
    
    cout << "---------------------" << endl;
    
    cout << "Checking pop_back function..." << endl;
    cout << "Size before pop_back function: " << x.size() << endl;
    x.pop_back();
    cout << "Size after pop_back function: " << x.size() << endl;
    
    cout << "---------------------" << endl;
    
    cout << "Checking resize function..." << endl; 
    cout << "Values in array before resize function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    cout << "Enter value to resize array to: ";
    cin >> size;
    cout << endl;
    cout << "Enter value for array elements: ";
    cin >> value;
    cout << endl;
    cout << "Size before resize function: " << x.size() << endl;
    x.resize(size, value);
    cout << "Values in array after push_back function are: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << x.at(i) << " ";
    }
    cout << endl;
    cout << "Size after resize function: " << x.size() << endl;
    
    cout << "---------------------" << endl;
    
    cout << "Checking reserve function..." << endl; 
    cout << "Enter requested capacity size: ";
    cin >> n;
    cout << endl;
    cout << "Capacity before reserve function: " << x.capacity() << endl;
    x.capacity();
    cout << "Capacity after reserve function: " << x.capacity() << endl;
    
    cout << "---------------------" << endl;
    
    cout << "Checking clear function..." << endl;
    cout << "Size of array before clear function: " << x.size() << endl;
    x.clear();
    cout << "Size of array after clear function: " << x.size() << endl;    
    
    return 0;
}