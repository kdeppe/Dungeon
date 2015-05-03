#include "Level.h"

Level::Level() {
	minX = 0;
	maxX = 0;
	minY = 0;
	maxY = 0;
}

void Level::Gen() {
	GenLevel(ValidTiles, minX, maxX, minY, maxY);
}

Position Level::RandomValidTile() {
	srand(time(NULL));
	int index = rand() % ValidTiles.size();
	return ValidTiles.at(index);
}

bool Level::PositionValid(Position p) {
	for (int i = 0; i < ValidTiles.size(); i++) {
		if (ValidTiles.at(i).IsEqual(p))
			return true;
	}
	return false;
}

bool Level::PositionValid(int x, int y) {
	Position p = Position(x, y);
	return PositionValid(p);
}

void Level::LevelToMatrix(vector< vector<TileState> > &levelMatrix) {
	vector<TileState> row = vector<TileState>(maxY+1);
	levelMatrix = vector< vector<TileState> >(maxX+1, row);
	for (int i=minY; i<=maxY; i++) {
		for (int j=minX; j<=maxX; j++) {
			if (PositionValid(j, i)) {
				levelMatrix[j][i] = TileState::FREE;
			}
			else {
				levelMatrix[j][i] = TileState::WALL;
			}
		}
	}
}
