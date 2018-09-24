#include "Headers/Potion.h"

Potion::Potion()
{

}

std::string Potion::getName()
{
    return name;
}

int Potion::getPotionNumber()
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
