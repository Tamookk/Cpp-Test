//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef POTION_H
#define POTION_H

#include <ctime>
#include <iostream>
#include <random>

#include "Adventurer.h"

class Potion
{
public:
    Potion();
    void applyPotion(Adventurer &adv);

private:
    std::string name;
    double potionNumber;
};

#endif
