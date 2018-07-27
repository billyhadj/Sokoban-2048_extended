CPP = g++ --std=c++11 -Wall
INCLUDE=-I.

all : Jeu

Jeu : Jeu.cpp G_Sokoban.o G_2048.o Game.o Case.o
	$(CPP) -o Jeu Jeu.cpp G_Sokoban.o G_2048.o Game.o Case.o
Case.o : Case.cpp 
	$(CPP) -c Case.cpp
Game.o : Game.cpp  Case.o
	$(CPP) -c Game.cpp Case.o
G_Sokoban.o : G_Sokoban.cpp  Game.o Case.o
	$(CPP) -c G_Sokoban.cpp Game.o Case.o
G_2048.o : G_2048.cpp  Game.o
	$(CPP) -c G_2048.cpp

clean : 
	rm *.o
