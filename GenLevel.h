#ifndef __GENLEVEL_H__
#define __GENLEVEL_H__

#include "Position.h"
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

void GenLevel(vector<Position> &level, int &minX, int &maxX, int &minY, int &maxY);
int TileIndex(vector<Position> level, Position p);
#endif
