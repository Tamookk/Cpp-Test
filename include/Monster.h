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
    Monster();
    // In UML
    void rangedAttack(Entity e);
    void closeAttack(Entity e);

protected:
    std::string monsterNoise;
};

#endif
