//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef WITCH_H
#define WITCH_H

#include "Monster.h"
#include "OffensiveSpell.h"

class Witch : public Monster
{
public:
    Witch();
    ~Witch();
private:
    int mana;
    OffensiveSpell* spells[];
};

#endif
