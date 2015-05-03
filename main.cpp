#include <iostream>
#include "Level.h"

using namespace std;



int main(int argc, char** argv) {
	
	Level level = Level();
	level.Gen();
	
	
	level.Draw();
	
	
	return 0;
}


