#include "Position.h"


Position::Position (int xv, int yv) {
	x = xv;
	y = yv;
}

bool Position::IsEqual(Position p) {
	return (x == p.x && y == p.y);
}
