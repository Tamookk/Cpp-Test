//
// Created by Joshua Sutton (5736894)
// 10/09/2018.
//

#include "Headers/Adventurer.h"

Adventurer::Adventurer()
{
    name = "AAAAAA";
    age = 20;
    currentHealth = 100;
    maximumHealth = 100;
}

Adventurer::Adventurer(std::string name, int age, int currentHealth, const int maximumHealth)
{
    this->name = name;
    this->age = age;
    this->currentHealth = currentHealth;
    this->maximumHealth = maximumHealth;
}

Adventurer::~Adventurer()
{

}