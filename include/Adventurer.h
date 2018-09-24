//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef ADVENTURER_H
#define ADVENTURER_H

#include <iostream>

#include "Headers/Entity.h"

class Adventurer : protected Entity
{
protected:
    int age;
    int deathHour;
    std::string killedBy;
public:
    void rangedAttack(Entity e);
    void closeAttack(Entity e);
    // Not in UML
    Adventurer();
};

#endif // ADVENTURER_H
