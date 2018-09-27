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
    Vampire(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, std::string noise = "I vant to suck your blood!");
    void stealLife(Entity &e);
    // not in UML
    std::string getType();
private:
    int fullness;
};

#endif
