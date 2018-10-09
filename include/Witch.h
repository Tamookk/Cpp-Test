//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef WITCH_H
#define WITCH_H

#include "Monster.h"
#include "Spell.h"

class Witch : public Monster
{
public:
    Witch(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0,
          int health = 100, std::string noise = "Heehee!", int mana = 0, int gold = 0);
    ~Witch();
    std::string getType();
    void doot(Entity &e);
    void castSpell(Entity &e);
    void howl(Entity &e);
    void stealLife(Entity &e);

private:
    int mana;
    int maxMana;
    Spell** spells = new Spell*[2];
};

#endif
