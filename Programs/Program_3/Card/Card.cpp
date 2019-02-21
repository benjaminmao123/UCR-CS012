#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

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