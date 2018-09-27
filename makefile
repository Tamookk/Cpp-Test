prog:				main.o Adventurer.o DefensiveMage.o DefensiveSpell.o Entity.o Monster.o OffensiveMage.o OffensiveSpell.o Potion.o Rogue.o Skeleton.o Spell.o Tree.o Vampire.o Warrior.o Werewolf.o Witch.o
					CC -o prog main.o DefensiveMage.o Adventurer.o DefensiveMage.o DefensiveSpell.o Entity.o Monster.o OffensiveMage.o OffensiveSpell.o Potion.o Rogue.o Skeleton.o Spell.o Tree.o Vampire.o Warrior.o Werewolf.o Witch.o
main.o:				main.cpp DefensiveMage.h
					CC -std=c++11 main.cpp
Adventurer.o:	 	Adventurer.cpp Adventurer.h
					CC -std=c++11 Adventurer.cpp
DefensiveMage.o:	DefensiveMage.cpp DefensiveMage.h Adventurer.h DefensiveSpell.h
					CC -std=c++11 DefensiveMage.cpp
DefensiveSpell.o:	DefensiveSpell.cpp DefensiveSpell.h
					CC -std=c++11 DefensiveSpell.cpp
Entity.o:			Entity.cpp Entity.h
					CC -std=c++11 Entity.cpp
Monster.o:			Monster.cpp Monster.h
					CC -std=c++11 Monster.cpp
OffensiveMage.o:	OffensiveMage.cpp OffensiveMage.h
					CC -std=c++11 OffensiveMage.cpp
OffensiveSpell.o:	OffensiveMage.cpp OffensiveMage.h
					CC -std=c++11 OffensiveSpell.cpp
Potion.o:			Potion.cpp Potion.h
					CC -std=c++11 Skeleton.cpp
Rogue.o:			Rogue.cpp Rogue.h
					CC -std=c++11 Rogue.cpp
Skeleton.o:			Skeleton.cpp Skeleton.h
					CC -std=c++11 Skeleton.cpp
Spell.o:			Spell.cpp Spell.h
					CC -std=c++11 Spell.cpp
Tree.o:				Tree.cpp Tree.h
					CC -std=c++11 Tree.cpp
Vampire.o:			Vampire.cpp Vampire.h
					CC -std=c++11 Vampire.cpp
Warrior.o:			Warrior.cpp Warrior.h
					CC -std=c++11 Warrior.cpp
Werewolf.o:			Werewolf.cpp Werewolf.h
					CC -std=c++11 Werewolf.cpp
Witch.o:			Witch.cpp Witch.h
					CC -std=c++11 Witch.cpp
