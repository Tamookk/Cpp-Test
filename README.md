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

* Fix UML diagrams
* Continue programming functionality:
	* Complete functionality for remaining classes.
	* Generate random spells for spell-casting entities.
	* Generate random entities.
	* Other stuff that isn't coming to me right now but it will, I promise.
* Make program loop
* Change UML diagram to better reflect final program.
* Create a makefile

## Acknowledgments

* My compsci professor for teaching me C++ and setting this assignment.

## Changelog

### 24-09-2018
* Created all files needed for project.

* Cleaned up directories.

* Started programming functionality inside files.

### 08-05-2018
* Initial commit, created all files.
