//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Potion.h"

Potion::Potion()
{
    name = "Potion of ";
    std::string words[] = {"Stuff", "Juice", "Effects", "Things", "Tasting"};

    // Randomly choose an alignment for the potion (has no impact on potion effect)
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 10);
    distribution(generator); // Generates same number first time every time, so running once
    int randomChance = distribution(generator)%2;
    std::string alignment;
    alignment = randomChance ? "Good " : "Bad ";
    name += alignment;

    // Randomly choose a word and add it to the potion name
    name += words[distribution(generator)%5];

    // Randomly set potion number between 0.0 and 1.0
    potionNumber = (double)distribution(generator)/10.0;
}

// Apply the potion
void Potion::applyPotion(Adventurer &adv)
{
    std::cout << name << " is being applied to adventurer " << adv.getName() << std::endl;
    // Randomly choose a good or bad effect
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 10);
    bool good = (bool)distribution(generator)%2;

    // Apply a randomly chosen good or bad effect on the adventurer
    if(good) // Either increase damage multiplier or reduce defence multiplier or add health if health less than 100
    {
        std::cout << "Potion has a good effect on adventurer " << adv.getName() << std::endl;
        int effect = distribution(generator)%3;
        switch(effect)
        {
        case 0: // Make adventurer's damage multiplier > 1
        {
            double damageMult = 1 + (double)distribution(generator)/10;
            std::cout << "Adventurer's damage multiplier was changed!" << std::endl;
            adv.setDamageMultiplier(damageMult);
            std::cout << "Adventurer now has a damage multiplier of " << damageMult << "." << std::endl;
            break;
        }
        case 1: // Reduces adventurer's defence multiplier
        {
            double defenceMult = 1 - (double)distribution(generator)/10;
            std::cout << "Adventurer's defence multiplier was changed!" << std::endl;
            adv.setDefenceMultiplier(defenceMult);
            std::cout << "Adventurer now has a defence multiplier of " << (1 + defenceMult) << "." << std::endl;
            break;
        }
        case 2: // Add health to the adventurer
        {
            std::cout << "Adventurer's health was increased!" << std::endl;
            adv.addHealth(distribution(generator) * 10);
            std::cout << "Adventurer now has " << adv.getHealth() << " HP!" << std::endl;
            break;
        }
        default: // Make adventurer invincible (hopefully never happens in practice)
            std::cout << "Uh-oh! This potion is other-worldly..." << std::endl;
            adv.setDamageMultiplier(0);
            std::cout << "Adventurer's defence multiplier is 0! They are invincible!" << std::endl;
            break;
        }
    }
    else // Either decrease damage multiplier or increase defence multiplier or reduce health
    {
        std::cout << "Potion has a bad affect on adventurer " << adv.getName() << std::endl;
        int effect = distribution(generator)%3;
        switch(effect)
        {
        case 0: // Make adventurer's damage multiplier < 1
        {
            double damageMult = 1 - (double)distribution(generator)/10;
            std::cout << "Adventurer's damage multiplier was changed!" << std::endl;
            adv.setDamageMultiplier(damageMult);
            std::cout << "Adventurer now has a damage multiplier of " << damageMult << "." << std::endl;
            break;
        }
        case 1: // Increases adventurer's defence multiplier
        {
            double defenceMult = 1 + (double)distribution(generator)/10;
            std::cout << "Adventurer's defence multiplier was changed!" << std::endl;
            adv.setDefenceMultiplier(defenceMult);
            std::cout << "Adventurer now has a defence multiplier of " << (1 - defenceMult) << "." << std::endl;
            break;
        }
        case 2: // Remove health to the adventurer
        {
            std::cout << "Adventurer's health was decreased!" << std::endl;
            adv.takeDamage(distribution(generator) * 10);
            std::cout << "Adventurer now has " << adv.getHealth() << " HP!" << std::endl;
            // Kill the adventurer if health reduces to below 0
            if(adv.getHealth() <= 0)
                adv.kill(adv);
            break;
        }
        default: // Make adventurer die instantly (hopefully never happens in practice)
            std::cout << "Uh-oh! This potion is other-worldly..." << std::endl;
            std::cout << "Adventurer dies instantly! RIP." << std::endl;
            adv.kill(adv);
            break;
        }
    }
}
