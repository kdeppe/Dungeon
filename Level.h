#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "Position.h"
#include "Enums.h"
#include "GenLevel.h"

using namespace std;

class Level {
	vector<Position> ValidTiles;
	public:
		int minX, maxX, minY, maxY;
		Level();
		void Gen();
		bool PositionValid(Position p);
		bool PositionValid(int x, int y);
		Position RandomValidTile();
		void LevelToMatrix(vector< vector<TileState> > &levelMatrix);

};

#endif
