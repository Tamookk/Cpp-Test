//
// Created by Joshua Sutton
// 10/09/2018.
//

#include <cstdlib>
#include <iostream>

#include "../include/DefensiveMage.h"
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
        return 1;

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

    DefensiveMage a1("Josh", 10, 0, false, 19);
    DefensiveMage a2;

    int freeGold = 0;

    bool loop = true;
    while(loop)
    {
        a1.closeAttack(a2);
        if(a2.getHealth() <= 0)
        {
            freeGold += a1.kill(a2);
            loop = false;
        }
        hour++;
    }

    return 0;
}
