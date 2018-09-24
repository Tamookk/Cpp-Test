//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Potion.h"

Potion::Potion()
{

}

std::string Potion::getName()
{
    return name;
}

double Potion::getPotionNumber()
{
    return potionNumber;
}

void Potion::setPotionNumber(double val)
{
    potionNumber = val;
}

void Potion::applyPotion(Adventurer adv)
{
    // stuff
}
