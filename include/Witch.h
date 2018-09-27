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
    Witch(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, std::string noise = "Heehee!", int mana = 0);
    ~Witch();
private:
    int mana;
    OffensiveSpell* spells[];
};

#endif
