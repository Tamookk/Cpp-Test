#ifndef OFFENSIVEMAGE_H
#define OFFENSIVEMAGE_H

#include <ctime>
#include <random>

#include "Adventurer.h"
#include "OffensiveSpell.h"

class OffensiveMage : public Adventurer
{
public:
    OffensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int age = 20, int mana = 0);
    ~OffensiveMage();
    // Not in UML
    std::string getType();
    void addSpell(int index, Spell* spell);
    void castSpell(Entity &e);
    int stealGold(Entity &e);
    void beChivalrous(Entity &e);

private:
    int mana;
    Spell** spells = new Spell*[2];
};

#endif
