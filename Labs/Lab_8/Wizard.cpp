#include <iostream>
#include <string>
#include "Wizard.h"
#include "Character.h"

using namespace std;

Wizard::Wizard(const string &n, double h, double a, int r):Character(WIZARD, n, h, a), rank(r)
{
    return;
}

void Wizard::attack(Character &opponent)
{
    double damage;
    
    if (isAlive())
    {
        if (opponent.getType() == WIZARD)
        {
            Wizard &opp = dynamic_cast<Wizard &>(opponent);
            damage = attackStrength * (static_cast<double>(rank)/opp.rank);
            opponent.damage(damage);
            cout << "Wizard " << name << " attacks " << opp.name << " --- POOF!!" << endl; 
            cout << opp.name << " takes " << damage << " damage." << endl;
        }
        else
        {
            damage = attackStrength;
            opponent.damage(damage);
            cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl; 
            cout << opponent.getName() << " takes " << damage << " damage." << endl;
        }
    }
    else
    {
        return;
    }
    
    return;
}