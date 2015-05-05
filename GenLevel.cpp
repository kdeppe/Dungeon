#include "GenLevel.h"

int maxDimensions = 15;
int maxTiles = 200;

void GenLevel(vector<Position> &level, int &minX, int &maxX, int &minY, int &maxY) {

	vector<Position> adjacents, exclude;

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

        if (abs(pUp.x) <= maxDimensions && abs(pUp.y) <= maxDimensions && TileIndex(level, pUp) == (-1) && TileIndex(adjacents, pUp) == (-1) && TileIndex(exclude, pUp) == (-1)) {
            adjacents.push_back(pUp);
        } else if (TileIndex(adjacents, pUp) != (-1)) {
            exclude.push_back(pUp);
            adjacents.erase(adjacents.begin()+ TileIndex(adjacents, pUp));
        }
        if (abs(pDown.x) <= maxDimensions && abs(pDown.y) <= maxDimensions && TileIndex(level, pDown) == (-1) && TileIndex(adjacents, pDown) == (-1) && TileIndex(exclude, pDown) == (-1)) {
            adjacents.push_back(pDown);
        } else if (TileIndex(adjacents, pDown) != (-1)) {
            exclude.push_back(pDown);
            adjacents.erase(adjacents.begin()+ TileIndex(adjacents, pDown));
        }
        if (abs(pLeft.x) <= maxDimensions && abs(pLeft.y) <= maxDimensions && TileIndex(level, pLeft) == (-1) && TileIndex(adjacents, pLeft) == (-1) && TileIndex(exclude, pLeft) == (-1)) {
            adjacents.push_back(pLeft);
        } else if (TileIndex(adjacents, pLeft) != (-1)) {
            exclude.push_back(pLeft);
            adjacents.erase(adjacents.begin()+ TileIndex(adjacents, pLeft));
        }
        if (abs(pRight.x) <= maxDimensions && abs(pRight.y) <= maxDimensions && TileIndex(level, pRight) == (-1) && TileIndex(adjacents, pRight) == (-1) && TileIndex(exclude, pRight) == (-1)) {
            adjacents.push_back(pRight);
        } else if (TileIndex(adjacents, pRight) != (-1)) {
            exclude.push_back(pRight);
            adjacents.erase(adjacents.begin()+ TileIndex(adjacents, pRight));
        }

        // Diagnostic section
        string out = "";
        for (int t=maxY; t>=minY; t--) {
            for (int u=minX; u<=maxX; u++) {
                if (TileIndex(level, Position(u, t)) != -1) {
                    out += " ";
                } else if (TileIndex(adjacents, Position(u, t)) != -1) {
                    out += (char)177;
                } else {
                    out += (char)219;
                }
            }
            out += "\n";
        }
        cout << out;
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

int TileIndex(vector<Position> level, Position p) {
    for (int i = 0; i< level.size(); i++) {
        if (level.at(i).IsEqual(p)) {
            return i;
        }
    }
    return -1;
}
