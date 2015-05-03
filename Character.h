#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Position.h"
#include "Level.h"

class Character {
	public:
		Position position;
		Character ();
		Character (int x, int y);
		void MoveLeft(Level level);
		void MoveRight(Level level);
		void MoveUp(Level level);
		void MoveDown(Level level);
		void MoveTo(Position pos);
		void MoveRandom(Level level);
};

#endif
