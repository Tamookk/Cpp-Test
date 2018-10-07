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

void Spell::printInfo()
{
    std::cout << "Name: " << this->name << "\nCost: " << this->cost << std::endl;
}

// Healing spell (defensive)
HealingSpell::HealingSpell(std::string name, int cost, int healingPower)
: Spell(name, cost)
{
    this->healingPower = healingPower;
}

void HealingSpell::castSpell(Entity &e)
{
    std::cout << "Casting a healing spell on " << e.getName() << std::endl;
    std::cout << e.getName() << " gains " << healingPower << " HP!\n" << std::endl;
    e.addHealth(healingPower);
}


// Defensive/offensive spell
DefenceMultiplierSpell::DefenceMultiplierSpell(std::string name, int cost, double defenceFactor)
: Spell(name, cost)
{
    this->defenceFactor = defenceFactor;
}

void DefenceMultiplierSpell::castSpell(Entity &e)
{
    std::cout << "Casting a defence spell on " << e.getName() << std::endl;
    std::cout << e.getName() << " now has a defence multiplier of " << defenceFactor << "!\n" << std::endl;
    e.setDefenceMultiplier(defenceFactor);
}


DamageMultiplierSpell::DamageMultiplierSpell(std::string name, int cost, double damageFactor)
: Spell(name, cost)
{
    this->damageFactor = damageFactor;
}

void DamageMultiplierSpell::castSpell(Entity &e)
{
    std::cout << "Casting a damage multiplier spell on " << e.getName() << std::endl;
    std::cout << e.getName() << " now has a damage multiplier of " << damageFactor << "!\n" << std::endl;
    e.setDamageMultiplier(damageFactor);
}


// Offensive spell
DamageSpell::DamageSpell(std::string name, int cost, int damage)
: Spell(name, cost)
{
    this->damage = damage;
}

void DamageSpell::castSpell(Entity &e)
{
    std::cout << "Casting a damage spell on " << e.getName() << std::endl;
    std::cout << e.getName() << " takes " << damage << "damage!\n" << std::endl;
    e.setDamageMultiplier(damage);
}
