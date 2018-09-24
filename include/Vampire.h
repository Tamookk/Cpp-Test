//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Entity.h"
#include "Monster.h"

class Vampire : public Monster
{
public:
    Vampire();
    void stealLife(Entity e);
private:
    int fullness;
};

#endif
