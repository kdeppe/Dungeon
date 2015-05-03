#include "Position.h"
#include <vector>

using namespace std;

void GenLevel(vector<Position> &level, int &minx, int &maxx, int &miny, int &maxy) {
	
	level.push_back(Position(1, 0));
	level.push_back(Position(1, 1));
	level.push_back(Position(0, 1));
	level.push_back(Position(-1, 1));
	level.push_back(Position(-1, 0));
	level.push_back(Position(-1, -1));
	level.push_back(Position(0, -1));
	level.push_back(Position(1, -1));	
	
	minx = -1;
	maxx = 1;
	miny = -1;
	maxy = 1;
}

