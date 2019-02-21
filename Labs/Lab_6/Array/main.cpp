#include <iostream>

using namespace std;

double mean(const double array[], int arraySize);

void remove(double array[], int &arraySize, int index);

void display(const double array[], int arraySize);

int main()
{
    int arraySize = 10;
    double array[arraySize];
    int userIndex;
    
    cout << "Enter 10 values:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cin >> array[i];
    }
    cout << endl;
    
    cout << "Mean: " << mean(array, arraySize) << endl;
    cout << endl;
    
    cout << "Enter index of value to be removed: ";
    cin >> userIndex;
    cout << endl;
    
    cout << "Before removing value: ";
    display(array, arraySize);
    
    remove(array, arraySize, userIndex);
    
    cout << "After removing value: ";
    display(array, arraySize);
}

double mean(const double array[], int arraySize)
{
    double meanValue = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        meanValue = meanValue + array[i]; 
    }
    
    meanValue = meanValue/arraySize;
    
    return meanValue;
}

void remove(double array[], int &arraySize, int index)
{
    if (!(index == arraySize-1))
    {
        for (int i = index; i < arraySize; ++i)
        {
            array[i] = array[i+1];
        }
        arraySize--;
    }
    else
    {
        arraySize--;
    }
    
    return;
}

void display(const double array[], int arraySize)
{
    for (int i = 0; i < arraySize-1; ++i)
    {
        cout << array[i] << ", ";
    }
    
    cout << array[arraySize-1] << endl;
    
    return;
}