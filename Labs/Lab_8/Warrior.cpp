#include <iostream>
#include <string>
#include "Warrior.h"
#include "Character.h"

using namespace std;

Warrior::Warrior(const string &n, double h, double a, const string &al) : Character(WARRIOR, n, h, a), allegiance(al)
{
    return;
}

void Warrior::attack(Character &opponent)
{
    if (isAlive())
    {
        if (opponent.getType() == WARRIOR)
        {
            Warrior &opp = dynamic_cast<Warrior &>(opponent);
            
            if (opp.allegiance == allegiance)
            {
                cout << "Warrior " << name << " does not attack Warrior " << opp.name << "." << endl;
                cout << "They share an allegiance with " << opp.allegiance << "." << endl;
                
                return;
            }
        }
        double damage = (health/MAX_HEALTH) * attackStrength;
        opponent.damage(damage);
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else
    {
        return;
    }
    
    return;
}
