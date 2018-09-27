#ifndef DEFENSIVEMAGE_H
#define DEFENSIVEMAGE_H

#include "Adventurer.h"
#include "DefensiveSpell.h"

class DefensiveMage : public Adventurer
{
public:
    DefensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int age = 20, int mana = 0);
    ~DefensiveMage();
    // not in uml
    std::string getType();

private:
    int mana;
    DefensiveSpell* spells = new DefensiveSpell[2];
};

#endif
