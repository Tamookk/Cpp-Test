//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef TREE_H
#define TREE_H

#include "Monster.h"
#include "Spell.h"

class Tree : public Monster
{
public:
    Tree(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0,
         int health = 100, std::string noise = "*leaves rustling*", int mana = 0, int gold = 0);
    ~Tree();
    std::string getType();
    void addSpell(int index, Spell* spell);
    void doot(Entity &e);
    void castSpell(Entity &e);
    void howl(Entity &e);
    void stealLife(Entity &e);

private:
    int mana;
    int maxMana;
    Spell** spells = new Spell*[2];
};

#endif // TREE_H
