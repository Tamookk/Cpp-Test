//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Potion.h"

Potion::Potion()
{
    name = "Potion of ";
    // randomly choose either bad or good and add to string
    // randomly choose a word and add it to the string

    // randomly set potion number between 0.00 and 1.00
    potionNumber = 0.50;
}

// Apply the potion
void Potion::applyPotion(Adventurer &adv)
{
    // Randomly choose a good or bad effect
    // (decrease damage or take damage)
    bool good = false;
    if(good)
    {
        // Either increase damage multiplier or reduce defence multiplier or add health if health less than 100
        std::cout << "Potion has a good affect on adventurer " << adv.getName() << std::endl;
        std::cout << "The potion changes adventurer's damage multiplier to " << (1 + potionNumber) << std::endl;
        adv.setDamageMultiplier(1 + potionNumber);
    }
    else
    {
        // Either decrease damage multiplier or increase defence multiplier or reduce health
        std::cout << "Potion has a bad affect on adventurer " << adv.getName() << std::endl;
        std::cout << "The adventurer takes " << (potionNumber * 100) << " damage." << std::endl;
        adv.takeDamage(potionNumber * 100);
    }
}
