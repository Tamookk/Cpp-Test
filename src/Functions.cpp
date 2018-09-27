#include "../include/Functions.h"

Adventurer* generateAdventurers()
{
    Adventurer* adventurers = new Adventurer[7];

    adventurers[0] = DefensiveMage();
    adventurers[1] = OffensiveMage();
    adventurers[2] = Rogue();
    adventurers[3] = Warrior();

    return adventurers;
}

// Generate a name for the adventurer
std::string generateName()
{
    // list of names and pick a random one?
}

// Generate a spell based on the given type
Spell generateSpell(std::string type)
{
    Spell spell;
    if(type == "defensive")
    {

    }
    else if(type == "offensive")
    {

    }
    else
    {

    }

    return spell;
}

// Generate a defensive mage
DefensiveMage generateDefensiveMage()
{
    // Generate a name for the mage
    std::string name = generateName();

    // Generate an age for the mage
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(50, 80);
    int age = distribution(generator);

    // Generate health for the mage
    distribution = std::uniform_int_distribution<int>(50, 70);
    int health = distribution(generator);

    // Generate ranged damage
    distribution = std::uniform_int_distribution<int>(1, 10);
    int rangedDamage = distribution(generator);
    // Generate mana
    int mana = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(1, 5);
    int closeDamage = distribution(generator);

    // Generate spells
    for(int i = 0; i < 2; i++)
    {

    }

    return DefensiveMage(name, closeDamage, rangedDamage, age, mana);
}

// Generate an offensive mage
OffensiveMage generateOffensiveMage()
{
    // Randomly choose a good or bad effect
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 10);
    bool good = (bool)distribution(generator)%2;
    // should generate to have an older age
    // health comparable to defensive mage
    // weak ranged damage
    // poor close damage
}

// Generate a rogue
Rogue generateRogue()
{
    // Randomly choose a good or bad effect
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 10);
    bool good = (bool)distribution(generator)%2;
    // should generate to be younger
    // health less than a warrior
    // highest distance damage in the game
    // mid-range close damage
}

// Generate a warrior
Warrior generateWarrior()
{
    // Randomly choose a good or bad effect
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 10);
    bool good = (bool)distribution(generator)%2;
    // should generate to be middleaged
    // highest health in game
    // no distance damage
    // highest close damage in game
}
