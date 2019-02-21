#include <iostream>
#include <cstring>
using namespace std;

void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string &s)
{
   if (s.size() < 2)
   {
      return;
   }
   else
   {
      string begin;
      string end;      
      begin = s.at(0);
      end = s.at(s.size()-1);
      s.erase(s.begin());
      s.erase(s.end()-1);
      flipString(s); 
      s = end + s + begin;   
   }
   
   return;
}