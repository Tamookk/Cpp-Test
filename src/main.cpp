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
int numOfAdventurers;
int numOfMonsters;

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
    cout << endl << "===Your Adventurers===" << endl;
    Adventurer** adventurers = generateAdventurers();
    numOfAdventurers = 7;
    for(int i = 0; i < 7; i++)
    {
        cout << "==" << adventurers[i]->getType() << "==" << endl;
        cout << *adventurers[i] << endl << endl;
    }


    // Main program loop
    cout << endl << "===Main Loop===" << endl;
    for(int i = 0; i < numHours; i++)
    {
        hour++;

        cout << "-Hour " << hour << "-" << endl;
        // Check if an encounter is to be had this hour
        if(distribution(generator) < probabilityOfEncounter)
        {
            cout << "Random Encounter!!" << endl;
            // Generate the monsters
            Monster** monsters = generateMonsters();

            // Continue until all adventurers or monsters are dead
            while(numOfAdventurers != 0 || numOfMonsters != 0)
            {
                // Have adventurers fight monsters
                for(int i = 0; i < numOfAdventurers; i++)
                {
                    // Randomly pick a monster
                    distribution = std::uniform_int_distribution<int>(0, numOfMonsters - 1);
                    int monster = distribution(generator);

                    // Randomly pick an action for the fighter based on their class
                    if(adventurers[i]->getType() == "Offensive Mage" || adventurers[i]->getType() == "Defensive Mage")
                    {
                        // Either do a close or ranged attack, or cast a spell
                        distribution = std::uniform_int_distribution<int>(0, 2);
                        switch(distribution(generator))
                        {
                            case 0: // Close attack
                            {
                                if(adventurers[i]->getLocation() == "far")
                                {
                                    adventurers[i]->move("close");
                                }
                                adventurers[i]->closeAttack(*monsters[monster]);
                                break;
                            }
                            case 1: // Ranged attack
                            {
                                adventurers[i]->rangedAttack(*monsters[monster]);
                                break;
                            }
                            case 2: // Cast a spell
                            {
                                adventurers[i]->castSpell(*monsters[monster]);
                                break;
                            }
                            default:
                            {
                                cout << adventurers[i]->getName() << " got confused and hurt themselves.\nThey take ";
                                cout << hour << " damage.";
                                adventurers[i]->takeDamage(hour);
                                break;
                            }
                        }
                    }
                    else if(adventurers[i]->getType() == "Rogue")
                    {
                        // Either do a close or ranged attack, or steal
                        distribution = std::uniform_int_distribution<int>(0, 2);
                        switch(distribution(generator))
                        {
                            case 0: // Close attack
                            {
                                adventurers[i]->closeAttack(*monsters[monster]);
                                break;
                            }
                            case 1: // Ranged attack
                            {
                                adventurers[i]->rangedAttack(*monsters[monster]);
                                break;
                            }
                            case 2: // Steal
                            {
                                adventurers[i]->stealGold(*monsters[monster]);
                                break;
                            }
                            default:
                            {
                                cout << adventurers[i]->getName() << " got confused and hurt themselves.\nThey take ";
                                cout << hour << " damage.";
                                adventurers[i]->takeDamage(hour);
                                break;
                            }
                        }
                    }
                    else if(adventurers[i]->getType() == "Warrior")
                    {
                        // Either do a close or ranged attack, or be chivalrous
                        distribution = std::uniform_int_distribution<int>(0, 2);
                        switch(distribution(generator))
                        {
                            case 0: // Close attack
                            {
                                adventurers[i]->closeAttack(*monsters[monster]);
                                break;
                            }
                            case 1: // Ranged attack
                            {
                                adventurers[i]->rangedAttack(*monsters[monster]);
                                break;
                            }
                            case 2: // Be chivalrous
                            {
                                adventurers[i]->beChivalrous(*monsters[monster]);
                                break;
                            }
                            default:
                            {
                                cout << adventurers[i]->getName() << " got confused and hurt themselves.\nThey take ";
                                cout << hour << " damage.";
                                adventurers[i]->takeDamage(hour);
                                break;
                            }
                        }
                    }

                    //  - when all adventurers done, do same for monsters
                    //  - keep going with battle loop until each adventurer or monster dead
                }
            }

            delete [] monsters;
        }
        else
        {
            cout << "No monsters were encountered..." << endl;
        }
        cout << endl;
    }

    delete [] adventurers;

    return 0;
}
