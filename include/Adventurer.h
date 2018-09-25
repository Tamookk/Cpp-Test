//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef ADVENTURER_H
#define ADVENTURER_H

#include <iostream>

#include "Entity.h"

class Adventurer : public Entity
{
public:
    Adventurer(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0,
               bool canCastSpells = false, int age = 20);
    void rangedAttack(Entity &e);
    void closeAttack(Entity &e);

protected:
    int age;
};

#endif
