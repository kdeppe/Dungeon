#include "GenLevel.h"

int maxDimensions = 10;
int maxTiles = 50;

void GenLevel(vector<Position> &level, int &minX, int &maxX, int &minY, int &maxY) {

	vector<Position> adjacents;

	//Initialize level with single tile at (0, 0)
	level.push_back(Position(0, 0));
	adjacents.push_back(Position(1, 0));
	adjacents.push_back(Position(-1, 0));
	adjacents.push_back(Position(0, 1));
	adjacents.push_back(Position(0, -1));

	minX = -1; //Include layer of wall around the outside
	maxX = 1;
	minY = -1;
	maxY = 1;

    int index;
    Position p;
    srand(time(NULL));
    for (int j=0; j<maxTiles; j++) {
        index = rand() % adjacents.size();
        p = adjacents.at(index);
        level.push_back(p);
        adjacents.erase(adjacents.begin() + index);

        minX = min(minX, (p.x-1));
        maxX = max(maxX, (p.x+1));
        minY = min(minY, (p.y-1));
        maxY = max(maxY, (p.y+1));

        Position pUp = Position(p.x, p.y+1);
        Position pDown = Position(p.x, p.y-1);
        Position pLeft = Position(p.x-1, p.y);
        Position pRight = Position(p.x+1, p.y);

        if (abs(pUp.x) <= maxDimensions && abs(pUp.y) <= maxDimensions && not TileExists(level, pUp)) {
            adjacents.push_back(pUp);
        }
        if (abs(pDown.x) <= maxDimensions && abs(pDown.y) <= maxDimensions && not TileExists(level, pDown)) {
            adjacents.push_back(pDown);
        }
        if (abs(pLeft.x) <= maxDimensions && abs(pLeft.y) <= maxDimensions && not TileExists(level, pLeft)) {
            adjacents.push_back(pLeft);
        }
        if (abs(pRight.x) <= maxDimensions && abs(pRight.y) <= maxDimensions && not TileExists(level, pRight)) {
            adjacents.push_back(pRight);
        }

        // Diagnostic section
        for (int t=maxY; t>=minY; t--) {
            for (int u=minX; u<=maxX; u++) {
                if (TileExists(level, Position(u, t))) {
                    cout << " ";
                } else if (TileExists(adjacents, Position(u, t))) {
                    cout << (char)177;
                } else {
                    cout << (char)219;
                }
            }
            cout << "\n";
        }
        Sleep(400);
    }


    // Translate level to align corner with (0, 0)
    // Allows vector indexing without offsets
	for (int i=0; i<level.size(); i++) {
		level.at(i).x -= minX;
		level.at(i).y -= minY;
	}

	maxX -= minX;
	maxY -= minY;
	minX = 0;
	minY = 0;
}

bool TileExists(vector<Position> level, Position p) {
    for (int i = 0; i< level.size(); i++) {
        if (level.at(i).IsEqual(p)) {
            return true;
        }
    }
    return false;
}
