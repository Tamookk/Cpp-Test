//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity
{
public:
    Monster(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int health = 100, std::string noise = "grr", int gold = 0);
    virtual ~Monster(){};
    void rangedAttack(Entity &e);
    void closeAttack(Entity &e);
    // Not in UML
    virtual std::string getType() = 0;
    virtual void castSpell(Entity &e) = 0;
    virtual void doot(Entity &e) = 0;
    virtual void howl(Entity &e) = 0;
    virtual void stealLife(Entity &e) = 0;

protected:
    std::string monsterNoise;
};

#endif
