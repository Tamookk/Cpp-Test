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
    Entity(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, bool canCastSpells = false);
    void move(std::string location);
    int getGold();
    void addGold(int amount);
    void takeDamage(int damage);
    void addHealth(int health);
    // Not in UML
    friend std::ostream& operator<<(std::ostream& stream, const Entity e);
    std::string getName();
    int getHealth();
    void setDamageMultiplier(double val);
    void setDefenceMultiplier(double val);
    void setMaximumHealth(int val);
    void setHealth(int val);
    int getMaxHealth();
    void removeGold(int val);

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
    double defenceMultiplier;
};

#endif
