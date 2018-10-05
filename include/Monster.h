//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

#include "Entity.h"

class Monster : public Entity
{
public:
    // Not in UML
    Monster(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int health = 100, std::string noise = "grr");
    // In UML
    void rangedAttack(Entity &e);
    void closeAttack(Entity &e);
    // Not in UML
    virtual std::string getType() = 0;

protected:
    std::string monsterNoise;
};

#endif
