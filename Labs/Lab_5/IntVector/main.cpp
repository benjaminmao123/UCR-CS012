#include <iostream>
#include <vector>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

int main()
{
    unsigned size = 5;
    IntVector x(size, 3);
    
    cout << "Values in array are: ";
    for (unsigned int i = 0; i < 5; ++i)
    {
        cout << x.at(i) << " ";
    }
    
    cout << "Size: " << x.size() << endl;
    cout << "Capacity: " << x.capacity() << endl;
    cout << "Empty? " << x.empty() << endl;  
    cout << x.at(-1) << endl;
    return 0;
}


/*void test1()
{
    IntVector x;
    
    for (int i = 0; i < 5; ++i)
    {
        x.IntVector(5, i);
        cout << "Value of the elements in the array: " << x.at(i) << " ";
    }
    
    cout << "Size: " << x.size() << endl;
    cout << "Capacity: " << x.capacity << endl;
    cout << "Empty? " << x.empty() << endl;  
    
    return;
}*/
