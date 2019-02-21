#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

using namespace std;
    
    int binaryHelper(int arr[], int begin, int end, int key);
    int bSearch(int arr[], int arrSize, int key);
        
    int bSearch(int arr[], int arrSize, int key)
    {
        return binaryHelper(arr, 0, arrSize-1, key);
    }
        
    int binaryHelper(int arr[], int begin, int end, int key)
    {
        if (end < begin)
        {
            return -1;
        }
            
        int mid = (begin + end)/2;
            
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            return binaryHelper(arr, begin, mid - 1, key);
        }
        if (arr[mid] < key)
        {
            return binaryHelper(arr, mid + 1, end, key);
        }
            
        return -1;
    }

#endif