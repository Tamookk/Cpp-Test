//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef DEFENSIVEMAGE_H
#define DEFENSIVEMAGE_H

#include "Adventurer.h"
#include "Spell.h"

class DefensiveMage : public Adventurer
{
public:
    DefensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int health = 100, int age = 20, int mana = 0);
    ~DefensiveMage();
    std::string getType();
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
