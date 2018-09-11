//
// Created by Joshua Sutton (5736894)
// 10/09/2018.
//

#include <iostream>

#ifndef ADVENTURER_H
#define ADVENTURER_H


class Adventurer
{
private:
    std::string name;
    int age;
    int currentHealth;
    int maximumHealth;
public:
    Adventurer();
    Adventurer(std::string name, int age, int currentHealth, int maximumHealth);
    ~Adventurer();
};


#endif
