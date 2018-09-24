#ifndef OFFENSIVEMAGE_H
#define OFFENSIVEMAGE_H

#include "Adventurer.h"
#include "OffensiveSpell.h"

class OffensiveMage : public Adventurer
{
public:
    OffensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0,
                  bool canCastSpells = true, int age = 20);
    ~OffensiveMage();

private:
    int mana;
    OffensiveSpell* spells = new OffensiveSpell[5];
};

#endif
