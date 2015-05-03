#include <iostream>
#include "GenLevel.h"

using namespace std;

int main(int argc, char** argv) {
	
	vector<Position> level;
	GenLevel(level);
	
	for (int i=0; i<level.size(); i++) {
		cout << level.at(i).x << "," << level.at(i).y << "\n";
	}
	
	
	return 0;
}
