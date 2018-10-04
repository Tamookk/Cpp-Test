#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <iostream>
#include <random>

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

std::string generateName();
Spell generateSpell(std::string type);

Adventurer** generateAdventurers();
Monster** generateMonsters();

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
