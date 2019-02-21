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

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &cards);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &outputs, const vector<Card> &right);

int main()
{
    srand(2222);
    string userString;
    unsigned int userInput;
    unsigned int userInput2;
    Deck d;
    ofstream outFS;
    vector<Card> hand;
    double pairChances;
    unsigned int counter;
    string filename;
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> userString;
    cout << endl;
    
    if (userString == "Yes")
    {
        cout << "Enter name of output file: ";
        cin >> filename;
        cout << endl;
        cout << "Enter number of cards per hand: ";
        cin >> userInput;
        cout << endl;
        cout << "Enter number of deals (simulations): ";
        cin >> userInput2;
        cout << endl;
    }
    else if (userString == "No")
    {
        cout << "Enter number of cards per hand: ";
        cin >> userInput;
        cout << endl;
        cout << "Enter number of deals (simulations): ";
        cin >> userInput2;
        cout << endl;
    }
    for (unsigned int i = 0; i < userInput2; ++i)
    {
        d.shuffleDeck();
        
        for (unsigned int j = 0; j < userInput; ++i)
        {
            hand.push_back(d.dealCard());
        }
        
        if (hasPair(hand))
        {
            ++counter;
        }
        
        outFS << hand << endl;
        hand.clear();
    }

    pairChances = static_cast<double>((counter)/userInput2) * 100;
    
    cout << "Chances of receiving a pair in a hand of " << userInput2 << " cards is: " << pairChances << "%" << endl; 
    
    return 0;
}

bool hasPair(const vector<Card> &hand)
{
    bool pair = false;
    for (unsigned int i = 0; i < hand.size()-1; ++i)
    {
        for (unsigned int j = i + 1; j < hand.size(); ++j)
        {
            if (hand.at(i).getRank() == hand.at(j).getRank())
            {
                pair = true;
            }
        }
    }
    
    return pair;
}

ostream & operator<<(ostream &outputs, const vector<Card> &right)
{
    for (unsigned int i = 0; i < right.size()-1; ++i)
    {
        outputs << right.at(i) << ", ";
    }
    
    outputs << right.at(right.size()-1) << endl;
    
    return outputs;
}