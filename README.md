# C++ Test

Learning C++ pls ignore.

This program is a turn-based RPG... that runs by itself. A party of adventurers wander around battling monsters. Encounters are random.

A party of 7 adventurers is automatically created when the program is ran, one of each of the four classes, and 3 of other, randomly-chosen classes. The classes are:

* Warrior

* Offensive Mage

* Defensive Mage

* Rogue

Each hour, a random encounter may happen depending on the probability of an encounter happening, which is entered in when running the program. The adventurers and monsters battle, with each adventurer doing a random ability (e.g., a close range attack or casting a spell), followed by each monster.

Battles continue until everyone from either side is dead (obviously if all the adventurers die, the program ends). If the adventurers win, all of the ones that are still alive are fully healed (and their mana restored if they are a mage), and the treasure gained from the battle is split evenly among the party members. Any remaining treasure is randomly allocated to the adventurers. If a party member dies, their gold is split evenly among the survivors.

There is also a chance that a magic potion can be found that has a random effect on the adventurer that drinks it.

At the end of the adventure, a report on the state of the party and a summary of all the battles fought and treasures found is given. If an adventurer has died, then when and what killed them is given.

## Getting Started

Dunno why you want to but okay.

### Prerequisites

* A compiler (C++ 11)
* Computer
* Eyes

### Installing

Honestly the thing isn't done and doesn't work properly, and I assume that if you really want to look at the thing then you know how to compile and run it.

Personally my compilation instruction is `CC -std=c++11 -o RPA *.cpp`, which works for some reason. `CC` is some Solaris C++ compiler, I don't know anything about it other than that.

When running the program, it should be run as follows:

`./RPA n p`

Where `n` is the maximum number of hours the adventure runs for, and `p` is the probability of an encounter each hour. `n` will not go below 1 or above 45, and `p` will not go below 5 or above 95.

## Author

* Me

## Todo

* Nothing, the program works as per required by the assignment specification, and it is very, very unlikely I will return to this project in the future.

## Acknowledgments

* My compsci professor for teaching me C++ and setting this assignment.

* Names in the `names.txt` file were generated from [here](https://www.fantasynamegenerators.com/world-of-warcraft.php).

## Changelog

### 09-10-2018
* Readme file has been updated.

### 08-10-2018
* Final code commit. No more code will be changed from this point onwards.

* Segmentation faults have been fixed (for real this time).

* Memory leaks have been fixed.

* It now takes close-range classes (Warriors, Werewolves) one turn to move into a close range for a close range attack.

* Mana is now taken into account when casting spells.

* The type of entity that killed another entity is now given.

* Program output has been tidied.

* The random choosing of an adventurer to consume a potion has been fixed.

### 07-10-2018
* Segmentation faults have been fixed (but not really).

* Added the chance of a random adventurer finding and consuming a potion with a random (good or bad) effect each hour.

* Program now prints out a mage's spells (name and mana cost) when the mages are generated.

* Gold is now distributed amoung the alive adventurers when a monster is killed.

* The main loop is now finished.

### 06-10-2018
* Added the monster loop.

### 05-10-2018
* Generate a random amount of gold for a Monster when the Monster is created.

* Make helpful abilities and spells apply to friendlies only.

* Add health and age parameters to constructors for entities.

* Print out the monsters as they are generated for a given hour.

* Add a name generator - make a text file of names, read these names into a list, and pick a random one.

* Make a Monster die when its health drops below 0.

* Added the ability to use class-specific abilities in combat (e.g., stealing gold, casting spells).

* The hour now finishes and continues onto the next one if every entity on either side is dead.

### 04-10-2018
* Continue coding the main loop of the program.

### 03-10-2018
* Add code to generate the different types of Monster.

### 30-09-2018
* Add generating spells when a mage (offensive, defensive, tree, witch) is created.

### 27-09-2018
* Finished the code for generating adventurers.

* Finished programming the Spell class.

* Started coding the main program loop.

* Added a function that returns the type of entity.

### 25-09-2018
* Program the Skeleton, Potion, and Rogue classes.

* Fix some bugs.

### 24-09-2018
* Created all files needed for project.

* Cleaned up directories.

* Started programming functionality inside files.

### 08-09-2018
* Initial commit, created all files.
