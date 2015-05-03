#include "Character.h"

Character::Character() {
	position = Position();
}

Character::Character(int x, int y) {
	position = Position(x, y);
}

void Character::MoveLeft(Level level) {
	Position p = Position(position.x - 1, position.y);
	if (level.PositionValid(p)) {
		position.x--;
	}
}

void Character::MoveRight(Level level) {
	Position p = Position(position.x + 1, position.y);
	if (level.PositionValid(p)) {
		position.x++;
	}
}

void Character::MoveUp(Level level) {
	Position p = Position(position.x, position.y + 1);
	if (level.PositionValid(p)) {
		position.y++;
	}
}

void Character::MoveDown(Level level) {
	Position p = Position(position.x, position.y - 1);
	if (level.PositionValid(p)) {
		position.y--;
	}
}

void Character::MoveTo(Position pos) {
	position = pos;
}

void Character::MoveRandom(Level level) {
	srand(time(NULL));
	int r = rand() % 4;
	switch ( r ) {
		case 0:
			cout << "^";
			MoveUp(level);
			break;
		case 1:
			cout << "v";
			MoveDown(level);
			break;
		case 2:
			cout << "<";
			MoveLeft(level);
			break;
		case 3:
			cout << ">";
			MoveRight(level);
			break;
		default:
			break;
	}
}
