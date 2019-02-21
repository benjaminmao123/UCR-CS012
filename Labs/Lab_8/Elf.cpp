#include <iostream>
#include <string>
#include "Elf.h"
#include "Character.h"

using namespace std;

Elf::Elf(const string &n, double h, double a, const string &f):Character(ELF, n, h, a), family(f)
{
    return;
}

void Elf::attack(Character &opponent)
{
    if (isAlive())
    {
        if (opponent.getType() == ELF)
        {
            Elf &opp = dynamic_cast<Elf &>(opponent);
            
            if (opp.family == family)
            {
                cout << "Elf " << name << " does not attack Elf " << opp.name << "." << endl;
                cout << "They are both members of the " << opp.family << " family." << endl;
                
                return;
            }
        }      
        double damage = (health/MAX_HEALTH) * attackStrength;
        opponent.damage(damage);
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else
    {
        return;
    }
    
    return;
}