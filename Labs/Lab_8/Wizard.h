#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Wizard : public Character
{
    public:
        Wizard(const string &n, double h, double a, int r);
        void attack(Character &opponent);
    private:
        int rank;
};
#endif