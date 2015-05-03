#include "Position.h"
#include <vector>

using namespace std;

void GenLevel(vector<Position> &level, unsigned int &minX, unsigned int &maxX, unsigned int &minY, unsigned int &maxY) {
	
	int tMinX, tMaxX, tMinY, tMaxY;
	
	level.push_back(Position(1, 0));
	level.push_back(Position(1, 1));
	level.push_back(Position(0, 1));
	level.push_back(Position(-1, 1));
	level.push_back(Position(-1, 0));
	level.push_back(Position(-1, -1));
	level.push_back(Position(0, -1));
	level.push_back(Position(1, -1));
	level.push_back(Position(2, -1));
	level.push_back(Position(2, 0));
	level.push_back(Position(2, 1));
	
	tMinX = -2; //Include layer of wall around the outside
	tMaxX = 3;
	tMinY = -2;
	tMaxY = 2;
	
	for (int i=0; i<level.size(); i++) {
		level.at(i).x -= tMinX;
		level.at(i).y -= tMinY;
	}
	
	tMaxX -= tMinX;
	tMaxY -= tMinY;
	tMinX = 0;
	tMinY = 0;
	
	minX = tMinX;
	maxX = tMaxX;
	minY = tMinY;
	maxY = tMaxY;	
}

