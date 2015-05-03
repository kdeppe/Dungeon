#include "Draw.h"

void Draw (Level level, Character character) {
	vector< vector<TileState> > levelMatrix;
	level.LevelToMatrix(levelMatrix);
	levelMatrix[character.position.x][character.position.y] = TileState::OCCUPIED;
	
	for (int i=level.maxY; i>=(int)level.minY; i--) {
		for (int j=level.minX; j<=level.maxX; j++) {
			if (levelMatrix[j][i] == TileState::WALL) {
				cout << (char)219;
			}
			else if (levelMatrix[j][i] == TileState::OCCUPIED) {
				cout << (char)2;
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	//cout << "Hello\n";
}
