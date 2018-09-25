//
// Created by Joshua Sutton
// 18/09/2018.
//

#include "../include/Entity.h"

// Constructor
Entity::Entity(std::string name, int closeDamage, int distanceDamage, bool canCastSpells)
{
    this->name = name;
    currentHealth = 100;
    maximumHealth = 100;
    damageMultiplier = 1.0;
    defenceMultiplier = 1.0;
    gold = 0;
    closeRangeDamage = closeDamage;
    this->distanceDamage = distanceDamage;
    this->canCastSpells = canCastSpells;
    location = "";
}

// Move the entity to a location (close or far)
void Entity::move(std::string location)
{
    if(location == "close" || location == "far")
        this->location = location;
    else
        std::cerr << "Not a valid location" << std::endl;
}

// Add gold to the entity
void Entity::addGold(int amount)
{
    gold += amount;
}

// Return the gold the entity has
int Entity::getGold()
{
    return gold;
}

// Take damage
void Entity::takeDamage(int damage)
{
    currentHealth -= damage*defenceMultiplier;
}

// Add health to the entity
void Entity::addHealth(int health)
{
    currentHealth += health;
    if(currentHealth > maximumHealth)
        currentHealth = maximumHealth;
}

// Get the entity's name
std::string Entity::getName() { return name; }

// get the entity's health
int Entity::getHealth() { return currentHealth; }

// Set the entity's damage multiplier
void Entity::setDamageMultiplier(double val) { damageMultiplier = val; }

// Set the entity's defence multiplier (lower is better)
void Entity::setDefenceMultiplier(double val) { defenceMultiplier = val; }

// Set the entity's maximum health
void Entity::setMaximumHealth(int val) { maximumHealth = val; }

// Set the entity's health
void Entity::setHealth(int val)
{
    currentHealth = val < maximumHealth ? val : maximumHealth;
}

// Get the entity's maximum health
int Entity::getMaxHealth() { return maximumHealth; }

// << operator
std::ostream& operator<<(std::ostream& stream, const Entity e)
{
    stream << "Name: " << e.name << "\nMax Health: " << e.maximumHealth << "\nGold: ";
    stream << e.gold << "\nClose Range Damage: " << e.closeRangeDamage;
    stream << "\nDistance Damage: " << e.distanceDamage << "\nCan Cast Spells: " << e.canCastSpells;
    return stream;
}
