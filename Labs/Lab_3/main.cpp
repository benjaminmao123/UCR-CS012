#include <iostream>
#include <cmath>

using namespace std;

class Rational
{
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      Rational(int wholeNumber); 
      Rational(int top, int bot); 
      const Rational add(const Rational &rightSide) const; 
      const Rational subtract(const Rational &rightSide) const; 
      const Rational multiply(const Rational &rightSide) const; 
      const Rational divide(const Rational &rightSide) const; 
      void display() const; 
};

Rational::Rational()
{
   numerator = 0;
   denominator = 1;
}

Rational::Rational(int wholeNumber)
{
   numerator = wholeNumber;
   denominator = 1;
}

Rational::Rational(int top, int bot)
{
   numerator = top;
   denominator = bot;
}

const Rational Rational::add(const Rational &rightSide) const
{
   Rational sumAdd = 0;
   //(a/b) + (c/d) = (ad + bc) / (b*d)
   sumAdd.numerator = (numerator*rightSide.denominator+denominator*rightSide.numerator);
   sumAdd.denominator = (denominator*rightSide.denominator);
   
   return sumAdd;
}

const Rational Rational::subtract(const Rational &rightSide) const
{
   Rational sumSubtract;
   //(a/b) - (c/d) = (ad - bc) / (b*d)
   sumSubtract.numerator = (numerator*rightSide.denominator-denominator*rightSide.numerator);
   sumSubtract.denominator =(denominator*rightSide.denominator);
   
   return sumSubtract;
}

const Rational Rational::multiply(const Rational &rightSide) const
{
   Rational sumMultiply;
   //(a/b) * (c/d) = (ac) / (bd)
   sumMultiply.numerator = (numerator*rightSide.numerator);
   sumMultiply.denominator = (denominator*rightSide.denominator);
   
   return sumMultiply;
}

const Rational Rational::divide(const Rational &rightSide) const
{
   Rational sumDivide;
   //(a/b) / (c/d) = (ad) / (cb)  
   sumDivide.numerator = (numerator*rightSide.denominator);
   sumDivide.denominator = (rightSide.numerator*denominator);
   
   return sumDivide;
}

void Rational::display() const
{
   cout << numerator << " " << "/" << " " << denominator;
   
   return;
}

Rational getRational();

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result);

int main() {
   Rational A, B, result;
   int choice;

   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;

   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;

   cout << "Enter Operation (1 - 4):" << endl
      << "1 - Addition (A + B)" << endl
      << "2 - Subtraction (A - B)" << endl
      << "3 - Multiplication (A * B)" << endl
      << "4 - Division (A / B)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 2) {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 3) {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 4) {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;

   return 0;
}

Rational getRational() {
   int choice;
   int numer, denom;

   cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
      << "1 - 2 parameters (numerator & denominator)" << endl
      << "2 - 1 parameter (numerator)" << endl
      << "3 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}