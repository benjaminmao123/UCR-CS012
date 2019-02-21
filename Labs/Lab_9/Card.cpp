#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

/*class Card {
 private:
    char suit;
    int rank;
 public:*/

    /* Assigns a default value of 2 of Clubs
    */
    //Card();


    /* Assigns the Card the suit and rank provided.
       suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
       If an invalid suit is provided, sets the suit to Clubs
       ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
       If an invalid rank is provided, sets the rank to 2
       Accepts lower or upper case characters for suit
    */  
    //Card(char, int);


    /* Returns the Card's suit
    */
    //char getSuit() const;


    /* Returns the Card's rank as an integer
    */
    //int getRank() const;

    /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */  
    //friend ostream & operator<<(ostream &, const Card &);
//};

Card::Card()
{
    suit = 'c';
    rank = 2;
}

Card::Card(char st, int r)
{
    suit = st;
    rank = r;
    st = tolower(st);
    
    if (st == 'c' || st == 'd' || st == 'h' || st == 's')
    {
        suit = st;
    }
    else 
    {
        suit = 'c';
    }
    
    if (r >= 1 && r <= 13)
    {
        rank = r;
    }
    else
    {
        rank = 2;
    }
    
    return;
}

char Card::getSuit() const
{
    return suit;
}

int Card::getRank() const
{
    return rank;
}

ostream & operator<<(ostream &out, const Card &rhs)
{
    if (rhs.rank == 1)
    {
        out << "Ace";
    }
    else if (rhs.rank == 11)
    {
        out << "Jack";
    }
    else if (rhs.rank == 12)
    {
        out << "Queen";
    }
    else if (rhs.rank == 13)
    {
        out << "King";
    }
    else if (rhs.rank >= 2 && rhs.rank <= 10)
    {
        out << rhs.rank;
    }
    
    out << " of ";
    
    if (rhs.suit == 'c')
    {
        out << "Clubs";
    }
    else if (rhs.suit == 'd')
    {
        out << "Diamonds";
    }
    else if (rhs.suit == 'h')
    {
        out << "Hearts";
    }
    else if (rhs.suit == 's')
    {
        out << "Spades";
    }
    
    return out;
}