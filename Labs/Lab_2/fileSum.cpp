#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string filename);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}

int fileSum(string filename)
{
   ifstream inFS;
   int x = 0;
   int sum = 0;
   
   cin >> filename;
   inFS.open(filename.c_str());
   if(!inFS)
   {
      cout << "Error opening " << filename << endl;
      exit (1);
   }
   
   inFS >> x;
   while(!inFS.fail())
   {
      sum = sum + x;
      inFS >> x;
   }
   
   inFS.close();
   return sum;
}