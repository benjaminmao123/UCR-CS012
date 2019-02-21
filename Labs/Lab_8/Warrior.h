#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Warrior : public Character
{
    public:
        Warrior(const string &name, double h, double a, const string &al);
        void attack(Character &opponent);
    private:
        string allegiance;
};
#endif