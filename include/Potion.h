//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef POTION_H
#define POTION_H

#include <iostream>

#include "Adventurer.h"

class Potion
{
public:
    // Not in UML
    Potion();
    std::string getName();
    double getPotionNumber();
    void setPotionNumber(double val);
    // In UML
    void applyPotion(Adventurer adv);

private:
    std::string name;
    double potionNumber;
};

#endif
