//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "Headers/Adventurer.h"

Adventurer::Adventurer()
{

}

// Make a ranged attack at an entity
void Adventurer::rangedAttack(Entity e)
{
    e.takeDamage(distanceDamage * damageMultiplier);
}

// Make a close attack at an entity
void Adventurer::closeAttack(Entity e)
{
    e.takeDamage(closeRangeDamage * damageMultiplier);
}
