//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef TREE_H
#define TREE_H

#include "Monster.h"
#include "DefensiveSpell.h"

class Tree : public Monster
{
public:
    Tree(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0,
         std::string noise = "*leaves rustling*", int mana = 0);
    ~Tree();

private:
    int mana;
    DefensiveSpell* spells[];
};

#endif // TREE_H
