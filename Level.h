#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "Position.h"
#include "Character.h"
#include <vector>

using namespace std;

class Level {
	vector<Position> ValidTiles;
	Character character = Character(0,0);
	public:
		int MinX, MaxX, MinY, MaxY;
		Level();
		Level(Character &chr);
		void Gen();
		void Draw();
		bool PositionValid(int PosX, int PosY);
		void RandomPlaceCharacter();
};

#endif
