
#ifndef __AI_H__
#define __AI_H__

#include <vector>
#include <array>
#include "GameRes.h"

namespace AI {
	std::vector<int> findRelativeByQueue(std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums> _map, const int _R, const int _C, int _r, int _c);
	//std::vector<int> findRelative(int _map[], int _x, int _y);
	bool checkInRange(int _v, int _min, int _max);
}

#endif