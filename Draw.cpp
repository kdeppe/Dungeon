#include "Draw.h"

void Draw (Level level, Character character) {
	vector< vector<TileState> > levelMatrix;
	level.LevelToMatrix(levelMatrix);
	levelMatrix[character.position.x][character.position.y] = TileState::OCCUPIED;

	string levelString = "";

	for (int i=level.maxY; i>=(int)level.minY; i--) {
		for (int j=level.minX; j<=level.maxX; j++) {
			if (levelMatrix[j][i] == TileState::WALL) {
				levelString += (char)219;
			}
			else if (levelMatrix[j][i] == TileState::OCCUPIED) {
				levelString += (char)2;
			}
			else {
				levelString += " ";
			}
		}
		levelString += "\n";
	}
	cout << levelString;
}
