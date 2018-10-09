//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef OFFENSIVEMAGE_H
#define OFFENSIVEMAGE_H

#include "Adventurer.h"
#include "Spell.h"

class OffensiveMage : public Adventurer
{
public:
    OffensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int health = 100, int age = 20, int mana = 0);
    ~OffensiveMage();
    std::string getType();
    void addSpell(int index, Spell* spell);
    void castSpell(Entity &e);
    int stealGold(Entity &e);
    void beChivalrous(Entity &e);
    void getSpellInfo();
    void addMana(int amt);

private:
    int mana;
    int maxMana;
    Spell* spells[2] = {0};
};

#endif
