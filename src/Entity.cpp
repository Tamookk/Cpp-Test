//
// Created by Joshua Sutton
// 18/09/2018.
//

#include "../include/Entity.h"

// Move the entity to a location (close or far)
void Entity::move(string location)
{
    if(location == "close" || location == "far")
        this->location = location;
    else
        std::cerr << "Not a valid location" << endl;
}

// Return the gold the entity has
int Entity::getGold()
{
    return gold;
}

// Add gold to the entity
void Entity::addGold(int amount)
{
    gold += amount;
}

// Take damage
void Entity::takeDamage(int damage)
{
    currentHealth -= damage;
}

// Add health to the entity
void Entity::addHealth(int health)
{
    currentHealth += health;
    if(currentHealth > maximumHealth)
        currentHealth = maximumHealth;
}

// == Not on UML diagram but needed ==
Entity::Entity()
{

}
