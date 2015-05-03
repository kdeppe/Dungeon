#include "GameLoop.h"

Level level;
Character character;

void Initialize () {
	level = Level();
	character = Character();
	level.Gen();
	character.MoveTo(level.RandomValidTile());
}

void GameLoop() {
	for (int i=0; i<10; i++) {
		clock_t LoopStart, LoopDuration;
		LoopStart = clock();
		
		character.MoveRandom(level);
		
		Draw(level, character);
				
		LoopDuration = clock() - LoopStart;
		sleep(1 - (LoopDuration/CLOCKS_PER_SEC));
	}
}
