#ifndef DEFENSIVEMAGE_H
#define DEFENSIVEMAGE_H

#include <ctime>
#include <random>

#include "Adventurer.h"
#include "DefensiveSpell.h"
#include "Spell.h"

class DefensiveMage : public Adventurer
{
public:
    DefensiveMage(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int health = 100, int age = 20, int mana = 0);
    ~DefensiveMage();
    // not in uml
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
