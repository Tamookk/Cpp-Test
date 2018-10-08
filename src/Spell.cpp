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

int Spell::getCost() { return cost; }

// Healing spell (defensive)
HealingSpell::HealingSpell(std::string name, int cost, int healingPower)
: Spell(name, cost)
{
    this->healingPower = healingPower;
}

void HealingSpell::castSpell(Entity &e)
{
    std::cout << " is casting a healing spell on " << e.getType() << " " << e.getName() << std::endl;
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
    std::cout << " is casting a defence spell on " << e.getType() << " " << e.getName() << std::endl;
    std::cout << e.getName() << " now has a defence multiplier of " << (defenceFactor < 1 ? (defenceFactor + 1) : (defenceFactor - 1));
    std::cout << "!\n" << std::endl;
    e.setDefenceMultiplier(defenceFactor);
}


DamageMultiplierSpell::DamageMultiplierSpell(std::string name, int cost, double damageFactor)
: Spell(name, cost)
{
    this->damageFactor = damageFactor;
}

void DamageMultiplierSpell::castSpell(Entity &e)
{
    std::cout << " is casting a damage multiplier spell on " << e.getType() << " " << e.getName() << std::endl;
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
    std::cout << " is casting a damage spell on " << e.getType() << " " << e.getName() << std::endl;
    std::cout << e.getName() << " takes " << damage << " damage!\n" << std::endl;
    e.setDamageMultiplier(damage);
}
