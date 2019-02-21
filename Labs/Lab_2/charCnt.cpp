#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string filename, char chars);

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Enter a character: ";
   cin >> ch;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

int charCnt(string filename, char chars)
{
   ifstream inFS;
   int charCount = 0;
   
   inFS.open(filename.c_str());
   
   if (!inFS.is_open())
   {
      cout << "Error opening " << filename << endl;
      exit (1);
   }
   
   while (inFS >> filename)
   {
      for (unsigned int i = 0; i < filename.size(); ++i)
      {
         if (filename.at(i) == chars)
         {
            ++charCount;
         }
      }
   }
   
   return charCount;
}
