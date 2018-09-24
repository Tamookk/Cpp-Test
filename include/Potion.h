//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef POTION_H
#define POTION_H

#include <iostream>

class Potion
{
private:
    std::string name;
    double potionNumber;

public:
    // Not in UML
    Potion();
    std::string getName();
    double getPotionNumber();
    void setPotionNumber(double val);
    // In UML
    void applyPotion(Adventurer adv);
};

#endif // POTION_H
