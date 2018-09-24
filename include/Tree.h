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
    Tree();
    ~Tree();

private:
    int mana;
    DefensiveSpell* spells[];
};

#endif // TREE_H
