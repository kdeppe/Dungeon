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
	for (int i=0; i<100; i++) {
		clock_t LoopStart, LoopDuration;
		LoopStart = clock();

		character.MoveRandom(level);

		Draw(level, character);

		LoopDuration = clock() - LoopStart;
		Sleep(500 - (LoopDuration/(CLOCKS_PER_SEC/1000)));
	}
}
