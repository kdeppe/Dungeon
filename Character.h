#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character {
	public:
		int PosX, PosY;
		Character (int x, int y);
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
};

#endif
