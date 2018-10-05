# C++ Test

Learning C++ pls ignore. This program is a role playing adventure. A party of adventurers wander around battling monsters and collecting treasure. Encounters are random, as are the treasures found.

A party of 7 adventurers is automatically created when the program is run, one of each of the four classes, and 3 of other, randomly-chosen classes. The classes are:

* Warrior

* Offensive Mage

* Defensive Mage

* Rogue

Each hour, a random encounter may happen depending on the probability of an encounter happening, which is entered in when running the program. The adventurers and monsters battle, with battles continuing until everyone from either side is dead (obviously if all the adventurers die, the program ends). If the adventurers win, all of the ones that are still alive are fully healed, and the treasure gained from the battle is split evenly among the party members. If a party member dies, their gold is split evenly among the survivors.

There is also a chance that a magic potion can be found that increases a random ability of an adventurer.

At the end of the adventure, a report on the state of the part and a summary of all the battles fought and treasures found is given. If an adventurer has died, then when and what killed them is given.

Other, finer details of how the program runs will be given as the program is developed.

## Getting Started

Dunno why you want to but okay.

### Prerequisites

* A compiler (C++ 11 compatible preferably)
* Computer
* Eyes
* No but really, I'm going to make a makefile for this eventually. The project is massive and deserving of one for now you'll have to compile it by hand (if you want to, that is).

### Installing

Honestly the thing isn't done and doesn't work properly, and I assume that if you reaaaaally want to look at the thing then you know how to compile and run it.

When running the program, it should be run as follows:

`./RPA n p`

Where `n` is the maximum number of hours the adventure runs for, and `p` is the probability of an encounter each hour.

## Author

* Me (Tumuk)

## Todo

### Overall Program:

* Make the monster loop.

* Fix the program crashing (absolutely no idea why this is happening, so rip me).

* Make an adventurer die if their health drops below 0.

* Move an entity to a location appropriate for an attack they want to do (i.e., move them to a close distance if they want to do a close range attack).

* Many, many various different fixes, improvements and implementations.

* Potentially a makefile.

## Acknowledgments

* My compsci professor for teaching me C++ and setting this assignment.

* Names in the `names.txt` file were generated from [here](https://www.fantasynamegenerators.com/world-of-warcraft.php).

## Changelog

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
