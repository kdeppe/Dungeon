#include "Position.cpp"
#include <vector>

void GenLevel(std::vector<Position> &level) {
	
			 
	level.push_back(Position(0, 0));
	level.push_back(Position(1, 0));
	level.push_back(Position(1, 1));
	level.push_back(Position(0, 1));
	level.push_back(Position(-1, 1));
	level.push_back(Position(-1, 0));
	level.push_back(Position(-1, -1));
	level.push_back(Position(0, -1));
	level.push_back(Position(1, -1));	
	
}

