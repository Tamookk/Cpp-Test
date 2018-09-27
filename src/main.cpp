//
// Created by Joshua Sutton
// 10/09/2018.
//

#include <cstdlib>
#include <iostream>

#include "../include/DefensiveMage.h"
#include "../include/Functions.h"
#include "../include/GlobalVariables.h"

using namespace std;

int hour;
int numHours;
int probabilityOfEncounter;

int main(int argc, char* argv[])
{
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
    Adventurer* adventurers = generateAdventurers();
    for(int i = 0; i < 7; i++)
    {
        cout << adventurers[i] << endl << endl;
    }

    delete [] adventurers;

    return 0;
}
