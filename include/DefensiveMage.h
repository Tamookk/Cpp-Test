#ifndef DEFENSIVEMAGE_H
#define DEFENSIVEMAGE_H

#include "Adventurer.h"
#include "DefensiveSpell.h"
#include "Spell.h"

class DefensiveMage : public Adventurer
{
public:
    DefensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int age = 20, int mana = 0);
    ~DefensiveMage();
    // not in uml
    std::string getType();
    void addSpell(int index, Spell spell);

private:
    int mana;
    Spell* spells = new Spell[2];
};

#endif
