#ifndef ELF_H
#define ELF_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Elf : public Character
{
    public:
        Elf(const string &name, double h, double a, const string &f);
        void attack(Character &opponent);
    private:
        string family;
};
#endif