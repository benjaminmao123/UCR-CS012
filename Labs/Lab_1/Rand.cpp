// This program plays a guessing game where you try to guess the number 
// the computer has picked.
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   int seed;
   cout << "Random Seed?" << endl << "? ";
   cin >> seed;
   srand(seed);
   
   int numberToGuess = (rand() % 100) + 1;

   cout << "Guess a number between 1 and 100." << endl << "? ";
  
   int guess;
   cin >> guess;
   
   while (numberToGuess != guess)
   {
      if (guess > numberToGuess)
      {
         cout << "Try lower." << endl << "? ";
      }
      else if (guess < numberToGuess)
      {
         cout << "Try higher." << endl << "? ";
      }
      cin >> guess;
   }

   cout << "You guessed right!!!" << endl;
   return 0;
}