//
// Created by Joshua Sutton
// 10/09/2018.
//

#include <cstdlib>
#include <iostream>
#include <random>

#include "../include/Functions.h"
#include "../include/GlobalVariables.h"

using namespace std;

int hour;
int numHours;
int probabilityOfEncounter;

int main(int argc, char* argv[])
{
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(1, 100);

    if(argc != 3)
    {
        cout << "Not enough arguments provided." << endl;
        cout << "./RPA [n] [p]" << endl << "n: maximum number of hours adventure should run for (1-48)" << endl;
        cout << "p: percentage chance of an encounter per hour (5-95)" << endl;
        return 1;
    }

    // Set up running time
    numHours = atoi(argv[1]);
    if(numHours < 1)
        numHours = 1;
    if(numHours > 48)
        numHours = 48;

    // Set up hour
    hour = 0;

    // Set up probability of encounter
    probabilityOfEncounter = atoi(argv[2]);
    if(probabilityOfEncounter < 5)
        probabilityOfEncounter = 5;
    if(probabilityOfEncounter > 95)
        probabilityOfEncounter = 95;

    cout << "Running for " << numHours << " hours." << endl;

    // Generate adventurers
    Adventurer** adventurers = generateAdventurers();
    for(int i = 0; i < 7; i++)
    {
        cout << "==" << adventurers[i]->getType() << "==" << endl;
        cout << *adventurers[i] << endl << endl;
    }


    // Main program loop

    cout << "==Main Loop==" << endl;
    for(int i = 0; i < numHours; i++)
    {
        hour++;

        cout << "-Hour " << hour << "-" << endl;
        if(distribution(generator) > probabilityOfEncounter)
        {
            cout << "Random Encounter!!" << endl;
            Monster** monsters = generateMonsters(hour);
            // generate random num of monsters between 1 and hour
            // have adventurers fight monsters
            //  - go through each adventurer
            //  - randomly pick a monster
            //  - randomly pick an action for the fighter
            //  - carry out action on monster
            //  - when all adventurers done, do same for monsters
            //  - keep going with battle loop until each adventurer or monster dead
            delete [] monsters;
        }
    }

    delete [] adventurers;

    return 0;
}
