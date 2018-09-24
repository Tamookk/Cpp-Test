//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef ADVENTURER_H
#define ADVENTURER_H

#include <iostream>

#include "Entity.h"

class Adventurer : protected Entity
{
public:
    void rangedAttack(Entity e);
    void closeAttack(Entity e);
    // Not in UML
    Adventurer();

protected:
    int age;
    int deathHour;
    std::string killedBy;
};

#endif
