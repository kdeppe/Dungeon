#include "Character.h"

Character::Character(int x, int y) {
	PosX = x;
	PosY = y;
}

void Character::MoveLeft() {
	PosX--;
}

void Character::MoveRight() {
	PosX++;
}

void Character::MoveUp() {
	PosY++;
}

void Character::MoveDown() {
	PosY--;
}
