//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Functions.h"
#include "../include/Witch.h"

Witch::Witch(std::string name, int closeDamage, int distanceDamage, int health, std::string noise, int gold, int mana)
: Monster(name, closeDamage, distanceDamage, health, noise, gold)
{
    this->mana = mana;
    maxMana = mana;
    canCastSpells = true;
    for(int i = 0; i < 2; i++)
        spells[i] = generateSpell("offensive");
}

Witch::~Witch()
{
    for(int i = 0; i < 2; i++)
        delete spells[i];

    delete [] spells;
}

// Get the type of the entity
std::string Witch::getType() { return std::string("Witch"); }

// Cast a spell
void Witch::castSpell(Entity &e)
{
    if(location == "close")
        move("far");
    // Pick a random spell and cast it
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 1);
    int spellNum = distribution(generator);

    // Check if the mage has enough mana to cast the spell
    if(mana < spells[spellNum]->getCost())
    {
        std::cout << getType() << " " << name << " tries to cast a spell, but fails!\nThey don't have enough mana.\n" << std::endl;
    }
    else
    {
        std::cout << "Witch " << name;
        spells[spellNum]->castSpell(e);
        mana -= spells[spellNum]->getCost();
    }
}

void Witch::doot(Entity &e){}
void Witch::howl(Entity &e){}
void Witch::stealLife(Entity &e){}
