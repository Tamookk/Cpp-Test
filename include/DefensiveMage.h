#ifndef DEFENSIVEMAGE_H
#define DEFENSIVEMAGE_H

#include "Adventurer.h"
#include "DefensiveSpell.h"

class DefensiveMage : public Adventurer
{
public:
    DefensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0,
                  bool canCastSpells = true, int age = 20);
    ~DefensiveMage();

private:
    int mana;
    DefensiveSpell* spells = new DefensiveSpell[5];
};

#endif
