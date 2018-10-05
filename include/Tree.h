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
    // not in UML
    std::string getType();
    void addSpell(int index, Spell* spell);

private:
    int mana;
    Spell** spells = new Spell*[2];
};

#endif // TREE_H
