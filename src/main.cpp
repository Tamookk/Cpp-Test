//
// Created by Joshua Sutton
// 10/09/2018.
//

#include <cstdlib>
#include <iostream>
#include <random>

#include "../include/Functions.h"
#include "../include/GlobalVariables.h"
#include "../include/Potion.h"

using namespace std;

int hour;
int numHours;
int probabilityOfEncounter;
int numOfAdventurers;
int numOfMonsters;
string* names;

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

    // Grab the list of names
    getNames();

    // Generate adventurers
    cout << endl << "===Your Adventurers===" << endl;
    Adventurer** adventurers = generateAdventurers();
    numOfAdventurers = 7;
    for(int i = 0; i < 7; i++)
    {
        cout << "==" << (*adventurers[i]).getType() << "==" << endl;
        cout << *adventurers[i] << endl;
        if(adventurers[i]->getType() == "Offensive Mage" || adventurers[i]->getType() == "Defensive Mage")
        {
            cout << "--Spell Info--" << endl;
            adventurers[i]->getSpellInfo();
        }
        cout << endl;
    }


    // Main program loop
    cout << endl << "===Main Loop===" << endl;
    for(int i = 0; i < numHours; i++)
    {
        int freeGold = 0;
        hour++;

        cout << "-Hour " << hour << "-" << endl;

        // Randomly find a potion and apply it to an adventurer
        if(distribution(generator)%2 == 1)
        {
            // Generate potion and apply to random adventurer
            cout << "Potion has been found!" << endl;
            Potion p;
            p.applyPotion(*adventurers[distribution(generator)%(numOfAdventurers-1)]);
            cout << endl;
        }

        // Check if an encounter is to be had this hour
        if(distribution(generator) < probabilityOfEncounter)
        {
            cout << "Random Encounter!!" << endl;
            // Generate the monsters
            Monster** monsters = generateMonsters();
            cout << "--Monsters this Round--" << endl;
            for(int i = 0; i < numOfMonsters; i++)
            {
                cout << "=" << monsters[i]->getType() << "=" << endl;
                cout << *monsters[i] << endl << endl;
            }
            // Continue until all adventurers or monsters are dead
            while(numOfAdventurers != 0 || numOfMonsters != 0)
            {
                // Have adventurers fight monsters
                for(int i = 0; i < numOfAdventurers; i++)
                {
                    // Go to the next adventurer if the ith one is dead
                    if(adventurers[i]->getHealth() <= 0)
                        continue;

                    // Randomly pick a monster
                    distribution = std::uniform_int_distribution<int>(0, numOfMonsters - 1);
                    int monster = distribution(generator);

                    // Make sure the monster is not dead
                    while(monsters[monster]->getHealth() == 0)
                        monster = distribution(generator);

                    // Randomly pick an action for the fighter based on their class
                    if(adventurers[i]->getType() == "Offensive Mage" || adventurers[i]->getType() == "Defensive Mage")
                    {
                        // Either do a close or ranged attack, or cast a spell
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
                            case 2: // Cast a spell
                            {
                                // Cast a spell on an adventurer if the mage is defensive
                                if(adventurers[i]->getType() == "Defensive Mage")
                                    adventurers[i]->castSpell(*adventurers[monster]);
                                else
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
                                adventurers[i]->beChivalrous(*adventurers[monster]);
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

                    // Kill the monster if its health drops below 0 and distribute the gold
                    if(monsters[monster]->getHealth() <= 0)
                    {
                        freeGold = adventurers[i]->kill(*monsters[monster]);

                        // Distribute the gold
                        if(freeGold%numOfAdventurers != 0)
                        {
                            cout << freeGold%numOfAdventurers << " gold was lost. Oops!" << endl;
                            freeGold -= freeGold%numOfAdventurers;
                            cout << freeGold/numOfAdventurers << " gold was given to each adventurer." << endl << endl;
                        }

                        for(int i = 0; i < 7; i++)
                        {
                            if(adventurers[i]->getHealth() > 0)
                                adventurers[i]->addGold(freeGold/numOfAdventurers);
                        }
                    }

                    // If all the monsters have died, go to the next loop
                    if(numOfMonsters == 0)
                        break;
                }

                if(numOfMonsters == 0)
                    break;

                // Have monsters fight adventurers
                for(int i = 0; i < numOfMonsters; i++)
                {
                    // Go to the next adventurer if the ith one is dead
                    if(monsters[i]->getHealth() <= 0)
                        continue;

                    // Randomly pick an adventurer
                    distribution = std::uniform_int_distribution<int>(0, numOfAdventurers - 1);
                    int adventurer = distribution(generator);

                    // Make sure the adventurer is not dead
                    while(adventurers[adventurer]->getHealth() == 0)
                        adventurer = distribution(generator);

                    // Randomly pick an action for the fighter based on their class
                    if(monsters[i]->getType() == "Tree" || monsters[i]->getType() == "Witch")
                    {
                        // Either do a close or ranged attack, or cast a spell
                        distribution = std::uniform_int_distribution<int>(0, 2);
                        switch(distribution(generator))
                        {
                            case 0: // Close attack
                            {
                                monsters[i]->closeAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 1: // Ranged attack
                            {
                                monsters[i]->rangedAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 2: // Cast a spell
                            {
                                // Cast a spell on an adventurer if the mage is defensive
                                if(monsters[i]->getType() == "Tree")
                                    monsters[i]->castSpell(*adventurers[adventurer]);
                                else
                                    monsters[i]->castSpell(*adventurers[adventurer]);
                                break;
                            }
                            default:
                            {
                                cout << monsters[i]->getName() << " got confused and hurt themselves.\nThey take ";
                                cout << hour << " damage.";
                                monsters[i]->takeDamage(hour);
                                break;
                            }
                        }
                    }
                    else if(monsters[i]->getType() == "Skeleton")
                    {
                        // Either do a close or ranged attack, or doot
                        distribution = std::uniform_int_distribution<int>(0, 2);
                        switch(distribution(generator))
                        {
                            case 0: // Close attack
                            {
                                monsters[i]->closeAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 1: // Ranged attack
                            {
                                monsters[i]->rangedAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 2: // Doot
                            {
                                monsters[i]->doot(*adventurers[adventurer]);
                                break;
                            }
                            default:
                            {
                                cout << monsters[i]->getName() << " got confused and hurt themselves.\nThey take ";
                                cout << hour << " damage.";
                                monsters[i]->takeDamage(hour);
                                break;
                            }
                        }
                    }
                    else if(monsters[i]->getType() == "Vampire")
                    {
                        // Either do a close or ranged attack, or suck blood
                        distribution = std::uniform_int_distribution<int>(0, 2);
                        switch(distribution(generator))
                        {
                            case 0: // Close attack
                            {
                                monsters[i]->closeAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 1: // Ranged attack
                            {
                                monsters[i]->rangedAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 2: // Suck blood
                            {
                                monsters[i]->stealLife(*adventurers[adventurer]);
                                break;
                            }
                            default:
                            {
                                cout << monsters[i]->getName() << " got confused and hurt themselves.\nThey take ";
                                cout << hour << " damage.";
                                monsters[i]->takeDamage(hour);
                                break;
                            }
                        }
                    }
                    else if(monsters[i]->getType() == "Werewolf")
                    {
                        // Either do a close or ranged attack, or howl
                        distribution = std::uniform_int_distribution<int>(0, 2);
                        switch(distribution(generator))
                        {
                            case 0: // Close attack
                            {
                                monsters[i]->closeAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 1: // Ranged attack
                            {
                                monsters[i]->rangedAttack(*adventurers[adventurer]);
                                break;
                            }
                            case 2: // Howl
                            {
                                monsters[i]->howl(*adventurers[adventurer]);
                                break;
                            }
                            default:
                            {
                                cout << monsters[i]->getName() << " got confused and hurt themselves.\nThey take ";
                                cout << hour << " damage.";
                                monsters[i]->takeDamage(hour);
                                break;
                            }
                        }
                    }

                    // Kill the adventurer if its health drops below 0
                    if(adventurers[adventurer]->getHealth() <= 0)
                        monsters[i]->kill(*adventurers[adventurer]);

                    // If all the adventurers have died, go to the next loop
                    if(numOfAdventurers == 0)
                        break;
                }

                if(numOfMonsters == 0)
                    break;

                if(numOfAdventurers == 0)
                    break;
            }

            delete [] monsters;
        }
        else
        {
            cout << "No monsters were encountered..." << endl;
        }
        cout << endl;

        if(numOfAdventurers == 0)
            break;

        if(numOfMonsters == 0)
            continue;
    }

    // Print the adventure summary
    cout << endl << "===Adventure Summary===" << endl;
    for(int i = 0; i < 7; i++)
    {
        cout << "==Adventurer " << i+1 << "==" << endl;
        cout << "Name: " << adventurers[i]->getName() << endl;
        cout << "Type: " << adventurers[i]->getType() << endl;
        cout << "Killed By: " << adventurers[i]->getKiller() << endl;
        cout << "Hour Killed: " << adventurers[i]->getHourKilled() << endl << endl;
    }

    delete [] adventurers;

    return 0;
}
