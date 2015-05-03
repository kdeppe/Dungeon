#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Level.h"
#include "GenLevel.h"

Level::Level() {
	character = Character(0,0);
	MinX = 0;
	MaxX = 0;
	MinY = 0;
	MaxY = 0;
}

Level::Level(Character &chr) {
	character = chr;
	MinX = 0;
	MaxX = 0;
	MinY = 0;
	MaxY = 0;
}

void Level::Gen() {
	GenLevel(ValidTiles, MinX, MaxX, MinY, MaxY);
	RandomPlaceCharacter();
}

void Level::Draw() {
	for (int i=(MaxY+1); i>=(MinY-1); i--) {
		for (int j=(MinX-1); j<=(MaxX+1); j++) {
			if (character.PosX == j && character.PosY == i) {
				cout << (char)2;
			}
			else if (PositionValid(j, i)) {
				cout << " ";
			}
			else {
				cout << (char)219;
			}
		}
		cout << "\n";
	}
}

void Level::RandomPlaceCharacter() {
	srand(time(NULL));
	int index = rand() % ValidTiles.size();
	int x = ValidTiles.at(index).x;
	int y = ValidTiles.at(index).y;
	character.MoveTo(x,y);
}

bool Level::PositionValid(int posx, int posy) {
	Position p = Position(posx, posy);
	for (int i = 0; i < ValidTiles.size(); i++) {
		if (ValidTiles.at(i).IsEqual(p))
			return true;
	}
	return false;
}
