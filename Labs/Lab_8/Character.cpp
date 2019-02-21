#include <iostream>
#include "Character.h"
#include <string>

using namespace std;

Character::Character(CharType type, const string &name, double health, double attackStrength):type(type), name(name), health(health), attackStrength(attackStrength)
{
    return;
}

CharType Character::getType() const
{
    return type;
}

const string & Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    return static_cast<int>(health);
}

void Character::setHealth(double h)
{
    health = h;
}

void Character::damage(double d)
{
    health = health - d;
}

bool Character::isAlive() const
{
    if (getHealth() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    return false;
}