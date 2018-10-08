//
// Created by Joshua Sutton
// 18/09/2018.
//

#include "../include/Entity.h"

// Constructor
Entity::Entity(std::string name, int closeDamage, int distanceDamage, int health)
{
    this->name = name;
    currentHealth = health;
    maximumHealth = health;
    damageMultiplier = 1.0;
    defenceMultiplier = 1.0;
    gold = 0;
    closeRangeDamage = closeDamage;
    this->distanceDamage = distanceDamage;
    location = "far";
}

// Move the entity to a location (close or far)
void Entity::move(std::string location)
{
    if(location == "close" || location == "far")
    {
        this->location = location;
        std::cout << "Moving to " << location << std::endl;
    }

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

// Get the entity's defence multiplier
double Entity::getDefenceMultiplier() { return defenceMultiplier; }

// Set the entity's maximum health
void Entity::setMaximumHealth(int val) { maximumHealth = val; }

// Get the entity's maximum health
int Entity::getMaxHealth() { return maximumHealth; }

// Set who killed the entity
void Entity::setKiller(std::string killer)
{
    killedBy = killer;
}

// Set the hour the entity died at
void Entity::setDeathHour() { deathHour = hour; }

// Kill an entity
int Entity::kill(Entity &e)
{
    std::string killer = name + " (" + getType() + ")";

    e.setKiller(killer);
    e.setDeathHour();

    std::cout << e.getType() << " " << e.getName() << " was killed by ";
    std::cout << name <<  " (" << getType() << "). RIP." << std::endl;
    std::cout << "They had " << e.getGold() << " gold coin(s)." << std::endl;

    int freeGold = e.getGold();
    e.addGold(-freeGold);
    return freeGold;
}

// Get the location of the entity
std::string Entity::getLocation() { return location; }

// << operator
std::ostream& operator<<(std::ostream& stream, const Entity &e)
{
    stream << "Name: " << e.name << "\nMax Health: " << e.maximumHealth << "\nGold: ";
    stream << e.gold << "\nClose Range Damage: " << e.closeRangeDamage;
    stream << "\nDistance Damage: " << e.distanceDamage;
    return stream;
}
