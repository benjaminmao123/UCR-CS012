#include <iostream>
#include <vector>
using namespace std;
#include<string>

class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
       - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


Date::Date()
{
   day = 1;
   month = 1;
   year = 2000;
   monthName = "January";
   
   return;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
   bool corrected = false;
   
   if (m > 12)
   {
      m = 12;
      corrected = true;
   }
   else if (m < 1)
   {
      m = 1;
      corrected = true;
     // cout<<"negative or 0";
    }
   
   if (d > daysPerMonth(m, y))
   {
      d = daysPerMonth(m, y);
      corrected = true;
   }
   else if (d < 1)
   {
      d = 1;
      corrected = true;
   }
   
   month = m;
   day = d;
   year = y;
   monthName = name(m);
  
   if (corrected == true)
   {
      cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
   }
   
   return;
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
   bool corrected = false;
   unsigned m;
   m = number(mn);
   string mn2 = mn;
   mn2.at(0) = toupper(mn2.at(0));
   //if (m ==0){cout <<"invalid "}
  
   if (m < 1)
   {
      m = 1;
   }
   
   if (m == 90)
   {
      m = 1;
      y = 2000;
      d = 1;
      mn2 = "January";
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   } 
   
   if (d > daysPerMonth(m, y))
   {
      d = daysPerMonth(m, y);
      corrected = true;
   }
   
   if (d == 0)
   {  
      d = 1;
      corrected = true;
   }
   
   day = d;
   year = y;
   monthName = mn2;
   month = m;

   if (corrected == true)
   {
      cout << "Invalid date values: Date corrected to " << month << "/" << d << "/" << y << "." << endl;
   }
   
   return;
}

void Date::printNumeric() const
{
   cout << "" << month << "/" << day << "/" << year; 
   
   return;
}

void Date::printAlpha() const
{
   cout << "" << monthName << " " << day << ", " << year;
   
   return;
}

bool Date::isLeap(unsigned y) const
{
   if ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0)) 
   {
      return true;
   } 
   else 
   {
      return false;
   }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
   if (m == 1) 
   {    
      return 31;
   } 
   else if (m == 2 && isLeap(y))
   {
      return 29;
   } 
   else if (m == 2 && !isLeap(y)) 
   {
      return 28;
   } 
   else if (m == 3) 
   {
      return 31;
   } 
   else if (m == 4) 
   {
      return 30;
   } 
   else if (m == 5) 
   {
      return 31;
   } 
   else if (m == 6) 
   {
      return 30;
   } 
   else if (m == 7) 
   {
      return 31;
   } 
   else if (m == 8) 
   {
      return 31;
   } 
   else if (m == 9) 
   {
      return 30;
   } 
   else if (m == 10) 
   {
      return 31;
   } 
   else if (m == 11) 
   {
      return 30;
   } 
   else if(m == 12) 
   {
      return 31;
   } 
  
   return 0;
}

string Date::name(unsigned m) const
{
   if (m == 1) 
   {
      return "January";
   } 
   else if (m == 2)
   {
      return "February";
   } 
   else if (m == 3)
   {
      return "March";
   } 
   else if (m == 4) 
   {
      return "April";
   } 
   else if (m == 5)
   {
      return "May";
   } 
   else if (m == 6)
   {
      return "June";
   } 
   else if (m == 7) 
   {
      return "July";
   } 
   else if (m == 8)
   {
      return "August";
   } 
   else if (m == 9) 
   {
      return "September";
   } 
   else if (m == 10) 
   {
      return "October";
   } 
   else if (m == 11) 
   {
      return "November";
   } 
   else if (m == 12) 
   {
      return "December";
   }
   
   return "";
}

unsigned Date::number(const string &mn) const
{
   if (mn == "January" || mn == "january") 
   {
      return 1;
   } 
   else if (mn == "February" || mn == "february")
   {
      return 2;
   } 
   else if (mn == "March" || mn == "march")
   {
      return 3;
   } 
   else if (mn == "April" || mn == "april") 
   {
      return 4;
   } 
   else if (mn == "May" || mn == "may") 
   {
      return 5;
   } 
   else if (mn == "June" || mn == "june") 
   {
      return 6;
   }
   else if (mn == "July" || mn == "july") 
   {
      return 7;
   } 
   else if (mn == "August" || mn == "august")
   {
      return 8;
   } 
   else if (mn == "September" || mn == "september") 
   {
      return 9;
   } 
   else if (mn == "October" || mn == "october")
   {
      return 10;
   }
   else if (mn == "November" || mn == "november")
   {
      return 11;
   }
   else if (mn == "December" || mn == "december") 
   {
      return 12;
   }
   else 
   {
      return 90;
   }
}


Date getDate();

/*void test1()
{
    cout <<"1. Default" << endl;
    Date x = Date();
    cout << "numeric: ";
    x.printNumeric(); 
    cout << endl;
    cout << "alpha: ";
    x.printAlpha();
    cout << endl;
    cout << "-------------------------" << endl;
}

void test2()
{
    cout << "2. Numeric Date: 13.3.1991" << endl;
    Date x = Date(13, 3, 1991);
    cout << "numeric: ";
    x.printNumeric();
    cout << endl;
    cout <<"alpha: ";
    x.printAlpha();
    cout << endl;
    cout << "--------------------------" << endl;
}

void test3()
{
    cout << "3. Alpha Date: -1, 3, 1991" << endl;
    Date x = Date(-1, 3, 1991);
    cout << "numeric: ";
    x.printNumeric();
    cout << endl;
    cout << "alpha: ";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------" << endl;
}

void test4()
{
    cout << "4. Invalid Numeric Date: 0.3.1991 -> 1.3.1991" << endl;
    Date x = Date(0, 3, 1991);
    cout << "numeric: ";
    x.printNumeric();
    cout << endl;
    cout << "alpha: ";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------" << endl;
}

void test5()
{
    cout << "5. Invalid Alpha Date: 1.adf.1991 -> 1.1.2000" << endl;
    Date x = Date("adf", 1, 1991);
    cout << "numeric: ";
    x.printNumeric();
    cout << endl;
    cout << "alpha: ";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------" << endl;
}
*/
int main() {
   
/*   test1();
	test2();
	test3();
	test4();
   test5();
*/
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}

