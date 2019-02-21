#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main()
{
    SortedSet x;
    IntList y;
    cout << "pushfront" << endl;
    x.push_front(20);
    cout << "list: ";
    y.display();
    cout << endl;
    
    cout << "pushback" << endl;
    x.push_back(30);
    y.display();
    cout << endl;
    
    cout << "insert_ordered" << endl;
    x.insert_ordered(10);
    y.display();
    cout << endl;
    
    return 0;
}