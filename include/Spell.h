//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef SPELL_H
#define SPELL_H

#include <iostream>

class Spell
{
public:
    // Not in UML
    Spell(std::string name = "AAA", int cost = 1);

protected:
    std::string name;
    int cost;
};

#endif
