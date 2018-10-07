//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef SPELL_H
#define SPELL_H

#include <iostream>

#include "Entity.h"

class Spell
{
public:
    Spell(std::string name = "AAA", int cost = 1);
    // not in UML
    void printInfo();
    virtual void castSpell(Entity &e) = 0;

protected:
    std::string name;
    int cost;
};

// Not in UML
// Defensive Spell
class HealingSpell : public Spell
{
public:
    HealingSpell(std::string name = "AAA", int cost = 1, int healingPower = 0);
    void castSpell(Entity &e);

private:
    int healingPower;
};

// Defensive/offensive spell
class DefenceMultiplierSpell : public Spell
{
public:
    DefenceMultiplierSpell(std::string name = "AAA", int cost = 1, double defenceFactor = 0.0);
    void castSpell(Entity &e);

private:
    double defenceFactor;
};

class DamageMultiplierSpell : public Spell
{
public:
    DamageMultiplierSpell(std::string name = "AAA", int cost = 1, double damageFactor = 0.0);
    void castSpell(Entity &e);

private:
    double damageFactor;
};

// Offensive spell
class DamageSpell : public Spell
{
public:
    DamageSpell(std::string name = "AAA", int cost = 1, int damage = 0);
    void castSpell(Entity &e);

private:
    int damage;
};

#endif
