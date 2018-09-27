#include "../include/Functions.h"

// Generate the adventurers
Adventurer* generateAdventurers()
{
    Adventurer* adventurers = new Adventurer[7];

    // Generate required 4 adventurers
    adventurers[0] = generateDefensiveMage();
    adventurers[1] = generateOffensiveMage();
    adventurers[2] = generateRogue();
    adventurers[3] = generateWarrior();

    // Generate random 3 adventurers
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(1, 4);
    int randomNum = distribution(generator);
    for(int i = 4; i < 7; i++)
    {
        switch(randomNum)
        {
        case 1:
        {
            adventurers[i] = generateDefensiveMage();
            break;
        }
        case 2:
        {
            adventurers[i] = generateOffensiveMage();
            break;
        }
        case 3:
        {
            adventurers[i] = generateRogue();
            break;
        }
        case 4:
        {
            adventurers[i] = generateWarrior();
            break;
        }
        default:
        {
            adventurers[i] = generateWarrior();
            break;
        }
        }
    }

    return adventurers;
}

// Generate a name for the adventurer
std::string generateName()
{
    return "";
}

// Generate a spell based on the given type
Spell generateSpell(std::string type)
{
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(1, 10);
    int spellNum = 0;

    Spell spell;
    if(type == "defensive")
    {
        // Pick a random defensive spell
        spellNum = distribution(generator)%3;
        switch(spellNum)
        {
        case 0: // Healing spell
        {
            // Generate random cost
            int cost = distribution(generator);
            // Generate random healing factor
            int healingFactor = cost*distribution(generator);
            // Generate spell
            spell = HealingSpell("Spell of Healing", cost, healingFactor);
            break;
        }
        case 1: // Defensive spell
        {
            int cost = distribution(generator);
            double defenceFactor = (cost * distribution(generator))/100;
            spell = DefenceMultiplierSpell("Spell of Good Defence", cost, defenceFactor);
            break;
        }
        case 2: // Damage multiplier spell
        {
            int cost = distribution(generator);
            double damageFactor = ((cost * distribution(generator))/100 + 1);
            spell = DamageMultiplierSpell("Spell of Increased Damage", cost, damageFactor);
            break;
        }
        default: // Spell that heals the entity by 100
        {
            int cost = distribution(generator);
            spell = HealingSpell("Spell of Lots of Healing", cost, 100);
            break;
        }
        }
    }
    else if(type == "offensive")
    {
        // Pick a random offensive spell
        spellNum = distribution(generator)%3;
        switch(spellNum)
        {
        case 0: // Damage spell
        {
            // Generate random cost
            int cost = distribution(generator);
            // Generate random healing factor
            int damage = cost*distribution(generator);
            // Generate spell
            spell = DamageSpell("Spell of Damage", cost, damage);
            break;
        }
        case 1: // Defensive spell
        {
            int cost = distribution(generator);
            double defenceFactor = 1 + (cost * distribution(generator))/100;
            spell = DefenceMultiplierSpell("Spell of Bad Defence", cost, defenceFactor);
            break;
        }
        case 2: // Damage multiplier spell
        {
            int cost = distribution(generator);
            double damageFactor = ((cost * distribution(generator))/100);
            spell = DamageMultiplierSpell("Spell of Lowered Damage", cost, damageFactor);
            break;
        }
        default: // Spell that damages the entity by 100
        {
            int cost = distribution(generator);
            spell = DamageSpell("Spell of Lots of Damage", cost, 100);
            break;
        }
        }
    }
    else // Default to a damage spell
    {
        spell = DamageSpell("Spell of Mega Damage", 1, 1000);
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
        generateSpell("defensive");
    }

    return DefensiveMage(name, closeDamage, rangedDamage, age, mana);
}

// Generate an offensive mage
OffensiveMage generateOffensiveMage()
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
        generateSpell("offensive");
    }

    return OffensiveMage(name, closeDamage, rangedDamage, age, mana);
}

// Generate a rogue
Rogue generateRogue()
{
    // Generate a name for the rogue
    std::string name = generateName();

    // Generate an age for the rogue
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(20, 40);
    int age = distribution(generator);

    // Generate health for the rogue
    distribution = std::uniform_int_distribution<int>(60, 80);
    int health = distribution(generator);

    // Generate ranged damage
    distribution = std::uniform_int_distribution<int>(10, 20);
    int rangedDamage = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(1, 10);
    int closeDamage = distribution(generator);

    // Generate thieving ability
    int thievingAbility = distribution(generator);

    return Rogue(name, closeDamage, rangedDamage, age, thievingAbility);
}

// Generate a warrior
Warrior generateWarrior()
{
    // Generate a name for the warrior
    std::string name = generateName();

    // Generate an age for the warrior
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(30, 50);
    int age = distribution(generator);

    // Generate health for the warrior
    distribution = std::uniform_int_distribution<int>(80, 100);
    int health = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(10, 20);
    int closeDamage = distribution(generator);

    // Generate chivalry
    distribution = std::uniform_int_distribution<int>(0, 10);
    int chivalry = distribution(generator);

    return Warrior(name, closeDamage, 0, age, chivalry);
}
