#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <iostream>
#include <random>

#include "../include/Adventurer.h"
#include "../include/DefensiveMage.h"
#include "../include/OffensiveMage.h"
#include "../include/Rogue.h"
#include "../include/Spell.h"
#include "../include/Warrior.h"

std::string generateName();
Spell generateSpell(std::string type);

Adventurer** generateAdventurers();
DefensiveMage* generateDefensiveMage();
OffensiveMage* generateOffensiveMage();
Rogue* generateRogue();
Warrior* generateWarrior();

#endif // FUNCTIONS_H
