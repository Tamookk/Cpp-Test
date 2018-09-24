//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef SKELETON_H
#define SKELETON_H

#include "Entity.h"
#include "Monster.h"

class Skeleton : public Monster
{
public:
    Skeleton();
    void doot(Entity e);

private:
    int dootAbility;
};

#endif
