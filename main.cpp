#include <iostream>
#include "GenLevel.h"
#include "Character.h"

using namespace std;

bool PositionValid(vector<Position> level, int posx, int posy) {
	Position p = Position(posx, posy);
	for (int i=0; i<level.size(); i++) {
		if (level.at(i).IsEqual(p))
			return true;
	}
	return false;
}

int main(int argc, char** argv) {
	
	vector<Position> level;
	int minx, maxx, miny, maxy;
	GenLevel(level, minx, maxx, miny, maxy);
	
	Character guy = Character(0, 1);
	
	for (int i=(maxy+1); i>=(miny-1); i--) {
		for (int j=(minx-1); j<=(maxx+1); j++) {
			if (guy.PosX == j && guy.PosY == i) {
				cout << (char)2;
			}
			else if (PositionValid(level, j, i)) {
				cout << " ";
			}
			else {
				cout << (char)219;
			}
		}
		cout << "\n";
	}
	
	
	return 0;
}


