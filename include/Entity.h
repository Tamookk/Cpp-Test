//
// Created by Joshua Sutton
// 18/09/2018.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity
{
public:
    void move(std::string location);
    int getGold();
    void addGold(int amount);
    void takeDamage(int damage);
    void addHealth(int health);
    // Not on UML
    Entity();

protected:
    std::string name;
    int currentHealth;
    int maximumHealth;
    double damageMultiplier;
    int gold;
    int closeRangeDamage;
    int distanceDamage;
    bool canCastSpells;
    // Not in UML but needed
    std::string location;
};

#endif
