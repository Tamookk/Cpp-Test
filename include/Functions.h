//
// Created by Joshua Sutton
// 27/09/2018.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include "Adventurer.h"
#include "DefensiveMage.h"
#include "Monster.h"
#include "OffensiveMage.h"
#include "Rogue.h"
#include "Skeleton.h"
#include "Spell.h"
#include "Tree.h"
#include "Vampire.h"
#include "Warrior.h"
#include "Werewolf.h"
#include "Witch.h"

void getNames();
std::string generateName();
Spell* generateSpell(std::string type);

Adventurer** generateAdventurers();
Monster** generateMonsters(int numOfMonsters);

DefensiveMage* generateDefensiveMage();
OffensiveMage* generateOffensiveMage();
Rogue* generateRogue();
Warrior* generateWarrior();

Skeleton* generateSkeleton();
Tree* generateTree();
Vampire* generateVampire();
Werewolf* generateWerewolf();
Witch* generateWitch();

#endif // FUNCTIONS_H
