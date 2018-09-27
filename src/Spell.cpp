//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Spell.h"

Spell::Spell(std::string name, int cost)
{
    this->name = name;
    this->cost = cost;
}

HealingSpell::HealingSpell(std::string name, int cost, int healingPower)
: Spell(name, cost)
{
    this->healingPower = healingPower;
}

void HealingSpell::castSpell(Entity &e)
{

}


// Defensive/offensive spell
DefenceMultiplierSpell::DefenceMultiplierSpell(std::string name, int cost, double defenceFactor)
: Spell(name, cost)
{
    this->defenceFactor = defenceFactor;
}

void DefenceMultiplierSpell::castSpell(Entity &e)
{

}


DamageMultiplierSpell::DamageMultiplierSpell(std::string name, int cost, double damageFactor)
: Spell(name, cost)
{
    this->damageFactor = damageFactor;
}

void DamageMultiplierSpell::castSpell(Entity &e)
{

}


// Offensive spell
DamageSpell::DamageSpell(std::string name, int cost, int damage)
: Spell(name, cost)
{
    this->damage = damage;
}

void DamageSpell::castSpell(Entity &e)
{

}
