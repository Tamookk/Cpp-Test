#ifndef OFFENSIVEMAGE_H
#define OFFENSIVEMAGE_H

#include "Adventurer.h"
#include "OffensiveSpell.h"

class OffensiveMage : public Adventurer
{
public:
    OffensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int age = 20, int mana = 0);
    ~OffensiveMage();
    // Not in UML
    virtual std::string getType();
    void addSpell(int index, Spell spell);

private:
    int mana;
    Spell* spells = new Spell[2];
};

#endif
