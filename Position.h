#ifndef __POSITION_H__
#define __POSITION_H__

class Position {
	public:	
		int x, y;
		Position ();
		Position (int,int);
		bool IsEqual(Position p);
};

#endif
