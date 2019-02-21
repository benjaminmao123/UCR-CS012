#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "Deck.h"
#include "Card.h"

using namespace std;

/* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.
*/
void sortBySuit(vector<Card> &v);

/* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.
*/
void mergeSort(vector<Card> &v, unsigned begin, unsigned end);

/* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.
*/
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize);

//This is the function you implemented for PROGRAM 3
ostream & operator<<(ostream &outputs, const vector<Card> &right);

int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}

/* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.
*/
void sortBySuit(vector<Card> &v)
{
   if (v.size() == 0)
   {
      return;
   }
   
   mergeSort(v, 0, v.size()-1);
   
   return;
}
/* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.
*/
void mergeSort(vector<Card> &v, unsigned begin, unsigned end) 
{
   if (begin < end)
   {
      unsigned int mid = (begin + end) / 2;
       
      mergeSort(v, begin, mid);
       
      mergeSort(v, mid + 1, end);
       
      merge(v, begin, mid, end);
   }
   
   return; 
}

/* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.
*/
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end)
{
   unsigned leftPos = 0;
   unsigned rightPos = 0;
   unsigned mergePos = 0;
   unsigned mergedSize = end - begin + 1;
   vector<Card> mergedCards(mergedSize);
   
   leftPos = begin;
   rightPos = mid + 1;
   
   while (leftPos <= mid && rightPos <= end)
   {
      if (v.at(leftPos).getSuit() == v.at(rightPos).getSuit())
      {
         if (v.at(leftPos).getRank() < v.at(rightPos).getRank())
         {
            mergedCards.at(mergePos) = v.at(leftPos);
            ++leftPos;
         }
         else
         {
            mergedCards.at(mergePos) = v.at(rightPos);
            ++rightPos;
         }
         
      }
      else if (v.at(leftPos).getSuit() < v.at(rightPos).getSuit())
      {
         mergedCards.at(mergePos) = v.at(leftPos);
         ++leftPos;
      }
      else
      {
         mergedCards.at(mergePos) = v.at(rightPos);
         ++rightPos;
      }
      
      ++mergePos;
   }
   
   while (leftPos <= mid)
   {
      mergedCards.at(mergePos) = v.at(leftPos);
      ++leftPos;
      ++mergePos;
   }
   
   while (rightPos <= end)
   {
      mergedCards.at(mergePos) = v.at(rightPos);
      ++rightPos;
      ++mergePos;
   }
   
   for (mergePos = 0; mergePos < mergedSize; ++mergePos)
   {
      v.at(begin + mergePos) = mergedCards.at(mergePos);
   }
   
   return;
}

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize)
{
   hand.resize(handSize);
   
   for (unsigned i = 0; i < hand.size(); ++i) 
   {
      hand.at(i) = d.dealCard();
   }
   
   return;
}



//This is the function you implemented for PROGRAM 3
ostream & operator<<(ostream & out, const vector<Card> &hand) 
{
   if (hand.size() == 0) 
   {
        return out;
   }
   
   for (unsigned int i = 0; i < hand.size() - 1; i++) 
   {
      out << hand.at(i) << ", ";
   }
   
   out << hand.at(hand.size() - 1);

   return out;
}