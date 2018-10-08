#include "../include/Functions.h"

// Grab all of the names from the name file
void getNames()
{
    std::ifstream nameFile("names.txt");
    std::string name;
    names = new std::string[40];

    // Check if file could be opened
    if(nameFile.fail())
    {
        std::cerr << "Error opening file \"" << "names.txt" << "\"." << std::endl;
        nameFile.close();
        exit(1);
    }

    // Get all the names
    for(int i = 0; i < 40; i++)
    {
        // Get the next line of name data
        std::getline(nameFile, name);
        names[i] = name;

        // Skip line if it can't be opened
        if(nameFile.bad())
        {
            std::cerr << "Error reading line. Skipping..." << std::endl;
            nameFile.clear();
            nameFile.ignore(100,'\n');
        }

        // Break if the end of file was reached
        if(nameFile.eof())
            nameFile.close();
            break;
    }
}

// Generate the adventurers
Adventurer** generateAdventurers()
{
    Adventurer** adventurers = new Adventurer*[7];

    // Generate required 4 adventurers
    DefensiveMage* tmpDM = generateDefensiveMage();
    OffensiveMage* tmpOM = generateOffensiveMage();
    Rogue* tmpRg = generateRogue();
    Warrior* tmpWr = generateWarrior();
    adventurers[0] = tmpDM;
    adventurers[1] = tmpOM;
    adventurers[2] = tmpRg;
    adventurers[3] = tmpWr;

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
            tmpDM = generateDefensiveMage();
            adventurers[i] = tmpDM;
            break;
        }
        case 2:
        {
            tmpOM = generateOffensiveMage();
            adventurers[i] = tmpOM;
            break;
        }
        case 3:
        {
            tmpRg = generateRogue();
            adventurers[i] = tmpRg;
            break;
        }
        case 4:
        {
            tmpWr = generateWarrior();
            adventurers[i] = tmpWr;
            break;
        }
        default:
        {
            tmpWr = generateWarrior();
            adventurers[i] = tmpWr;
            break;
        }
        }
        randomNum = distribution(generator);
    }

    return adventurers;
}

// Generate the monsters for the round
Monster** generateMonsters(int numOfMonsters)
{
    Skeleton* tmpSk;
    Tree* tmpTr;
    Vampire* tmpVm;
    Werewolf* tmpWr;
    Witch* tmpWt;

    // Generate the number of monsters for that hour);
    Monster** monsters = new Monster*[numOfMonsters];

    // Generate the monsters
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(1, 5);
    int randomNum = distribution(generator);
    for(int i = 0; i < numOfMonsters; i++)
    {
        switch(randomNum)
        {
        case 1:
        {
            tmpSk = generateSkeleton();
            monsters[i] = tmpSk;
            break;
        }
        case 2:
        {
            tmpTr = generateTree();
            monsters[i] = tmpTr;
            break;
        }
        case 3:
        {
            tmpVm = generateVampire();
            monsters[i] = tmpVm;
            break;
        }
        case 4:
        {
            tmpWr = generateWerewolf();
            monsters[i] = tmpWr;
            break;
        }
        case 5:
        {
            tmpWt = generateWitch();
            monsters[i] = tmpWt;
            break;
        }
        default:
        {
            tmpWt = generateWitch();
            monsters[i] = tmpWt;
            break;
        }
        }
        randomNum = distribution(generator);
    }

    return monsters;
}

// Generate a name for the adventurer
std::string generateName()
{
    // Grab a random name
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 39);
    return names[distribution(generator)];
}

// Generate a spell based on the given type
Spell* generateSpell(std::string type)
{
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(1, 10);
    int spellNum = 0;

    Spell* spell;
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
            spell = new HealingSpell("Spell of Healing", cost, healingFactor);
            break;
        }
        case 1: // Defensive spell
        {
            int cost = distribution(generator);
            double defenceFactor = (cost * distribution(generator))/100.0;
            spell = new DefenceMultiplierSpell("Spell of Good Defence", cost, defenceFactor);
            break;
        }
        case 2: // Damage multiplier spell
        {
            int cost = distribution(generator);
            double damageFactor = ((cost * distribution(generator))/100.0 + 1);
            spell = new DamageMultiplierSpell("Spell of Increased Damage", cost, damageFactor);
            break;
        }
        default: // Spell that heals the entity by 100
        {
            int cost = distribution(generator);
            spell = new HealingSpell("Spell of Lots of Healing", cost, 100);
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
            spell = new DamageSpell("Spell of Damage", cost, damage);
            break;
        }
        case 1: // Defensive spell
        {
            int cost = distribution(generator);
            double defenceFactor = 1 + (cost * distribution(generator))/100.0;
            spell = new DefenceMultiplierSpell("Spell of Bad Defence", cost, defenceFactor);
            break;
        }
        case 2: // Damage multiplier spell
        {
            int cost = distribution(generator);
            double damageFactor = ((cost * distribution(generator))/100.0);
            spell = new DamageMultiplierSpell("Spell of Lowered Damage", cost, damageFactor);
            break;
        }
        default: // Spell that damages the entity by 100
        {
            int cost = distribution(generator);
            spell = new DamageSpell("Spell of Lots of Damage", cost, 100);
            break;
        }
        }
    }
    else // Default to a damage spell
    {
        spell = new DamageSpell("Spell of Mega Damage", 1, 1000);
    }

    return spell;
}

// Generate a defensive mage
DefensiveMage* generateDefensiveMage()
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

    DefensiveMage* temp = new DefensiveMage(name, closeDamage, rangedDamage, health, age, mana);

    return temp;
}

// Generate an offensive mage
OffensiveMage* generateOffensiveMage()
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

    return new OffensiveMage(name, closeDamage, rangedDamage, health, age, mana);
}

// Generate a rogue
Rogue* generateRogue()
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

    return new Rogue(name, closeDamage, rangedDamage, health, age, thievingAbility);
}

// Generate a warrior
Warrior* generateWarrior()
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

    return new Warrior(name, closeDamage, 0, health, age, chivalry);
}

// Generate a Skeleton
Skeleton* generateSkeleton()
{
    // Generate a name for the skeleton
    std::string name = generateName();

    // Generate health for the skeleton
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(60, 80);
    int health = distribution(generator);

    // Generate ranged damage
    distribution = std::uniform_int_distribution<int>(10, 20);
    int rangedDamage = distribution(generator);
    // Generate gold
    int gold = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(1, 10);
    int closeDamage = distribution(generator);

    // Generate doot ability
    distribution = std::uniform_int_distribution<int>(15, 30);
    int dootAbility = distribution(generator);

    Skeleton* temp = new Skeleton(name, closeDamage, rangedDamage, health, "doot", dootAbility, gold);

    return temp;
}

// Generate a tree
Tree* generateTree()
{
    // Generate a name for the tree
    std::string name = generateName();

    // Generate a health for the tree
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(50, 70);
    int health = distribution(generator);

    // Generate ranged damage
    distribution = std::uniform_int_distribution<int>(1, 10);
    int rangedDamage = distribution(generator);
    // Generate mana
    int mana = distribution(generator);

    // Generate gold
    distribution = std::uniform_int_distribution<int>(10, 20);
    int gold = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(1, 5);
    int closeDamage = distribution(generator);

    Tree* temp = new Tree(name, closeDamage, rangedDamage, health, "*leaves rustling", mana, gold);

    // Generate spells
    for(int i = 0; i < 2; i++)
    {
        temp->addSpell(i, generateSpell("defensive"));
    }

    return temp;
}

// Generate a Vampire
Vampire* generateVampire()
{
    // Generate a name for the vampire
    std::string name = generateName();

    // Generate health for the vampire
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(60, 80);
    int health = distribution(generator);

    // Generate ranged damage
    distribution = std::uniform_int_distribution<int>(1, 10);
    int rangedDamage = distribution(generator);

    // Generate gold
    distribution = std::uniform_int_distribution<int>(10, 20);
    int gold = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(1, 10);
    int closeDamage = distribution(generator);
    // Generate fullness
    int fullness = distribution(generator);

    Vampire* temp = new Vampire(name, closeDamage, rangedDamage, health, "I vant to suck your blood!", fullness, gold);

    return temp;
}

// Generate a werewolf
Werewolf* generateWerewolf()
{
  // Generate a name for the werewolf
    std::string name = generateName();

    // Generate health for the werewolf
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(90, 120);
    int health = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(10, 15);
    int closeDamage = distribution(generator);

    // Generate loudness
    distribution = std::uniform_int_distribution<int>(1, 10);
    int loudness = distribution(generator);

    // Generate gold
    distribution = std::uniform_int_distribution<int>(10, 20);
    int gold = distribution(generator);

    Werewolf* temp = new Werewolf(name, closeDamage, 0, health, "awoo", loudness, gold);

    return temp;
}

// Generate a witch
Witch* generateWitch()
{
    // Generate a name for the witch
    std::string name = generateName();

    // Generate health for the witch
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(50, 70);
    int health = distribution(generator);

    // Generate ranged damage
    distribution = std::uniform_int_distribution<int>(1, 10);
    int rangedDamage = distribution(generator);
    // Generate mana
    int mana = distribution(generator);

    // Generate gold
    distribution = std::uniform_int_distribution<int>(10, 20);
    int gold = distribution(generator);

    // Generate close damage
    distribution = std::uniform_int_distribution<int>(1, 5);
    int closeDamage = distribution(generator);

    Witch* temp = new Witch(name, closeDamage, rangedDamage, health, "Heehee!", mana, gold);

    // Generate spells
    for(int i = 0; i < 2; i++)
    {
        temp->addSpell(i, generateSpell("offensive"));
    }

    return temp;
}
