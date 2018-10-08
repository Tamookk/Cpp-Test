//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef ADVENTURER_H
#define ADVENTURER_H

#include "Entity.h"
#include "Spell.h"

class Adventurer : public Entity
{
public:
    Adventurer(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int health = 100, int age = 20);
    virtual ~Adventurer(){};
    void rangedAttack(Entity &e);
    void closeAttack(Entity &e);
    // Not in UML
    std::string getKiller();
    int getHourKilled();
    virtual std::string getType() = 0;
    virtual void getSpellInfo() = 0;
    virtual void castSpell(Entity &e) = 0;
    virtual int stealGold(Entity &e) = 0;
    virtual void beChivalrous(Entity &e) = 0;
    virtual void addMana(int amt) = 0;

protected:
    int age;
};

#endif
