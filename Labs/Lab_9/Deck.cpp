#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Deck.h"
#include "Card.h"

using namespace std;

/*class Deck 
{
 private:
    vector<Card> theDeck;
    vector<Card> dealtCards;
 public:*/
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
    */
    //Deck();

    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
    */
   // Card dealCard();


    /* Places all cards back into theDeck and shuffles them into random order.
       Uses random_shuffle function from algorithm standard library.
    */
   // void shuffleDeck();


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
  //  unsigned deckSize() const;
//};

Deck::Deck()
{
    int rank = 0;
    char suit;
    for (rank = 13; rank >= 1; --rank)
    {
        suit = 's';
        theDeck.push_back(Card(suit, rank));
    }
    
    for (rank = 13; rank >= 1; --rank)
    {
        suit = 'h';
        theDeck.push_back(Card(suit, rank));
    }
    
    for (rank = 13; rank >= 1; --rank)
    {
        suit = 'd';
        theDeck.push_back(Card(suit, rank));
    }
    
    for (rank = 13; rank >= 1; --rank)
    {
        suit = 'c';
        theDeck.push_back(Card(suit, rank));
    }
    
    return;
}

Card Deck::dealCard()
{
    Card top;
    top = theDeck.back();
    dealtCards.push_back(theDeck.back());
    theDeck.pop_back();
    
    return top;
}

void Deck::shuffleDeck()
{
    for (unsigned int i = 0; i < dealtCards.size(); ++i)
    {
        theDeck.push_back(dealtCards.at(i));
    }
    
    dealtCards.resize(0);
    
    random_shuffle(theDeck.begin(), theDeck.end());
    
    return;
}

unsigned Deck::deckSize() const
{
    return theDeck.size();
}