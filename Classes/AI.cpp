
#include "AI.h"
#include "array"
#include "queue"
#include "functional"

namespace AI {
	using namespace std;
	bool checkInRange(int _v, int _min, int _max) {
		if (_v >= _min && _v < _max) {
			return true;
		}
		return false;
	}
	vector<int> findRelativeByQueue(std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums> _map, const int _R, const int _C, int _r, int _c) {
		bool aryFound[100] = { 0 };
		queue<pair<int, int>> aryRelative;
		vector<int> aryRet;
		std::array<int, 4> directionR = { -1, 0, 1, 0 };
		std::array<int, 4> directionC = { 0, -1, 0, 1 };
		
		int _p = _r*_C + _c;
		aryRelative.push(make_pair(_r, _c));
		aryRet.push_back(_p);
		aryFound[_p] = true;

		while (!aryRelative.empty()) {
			pair<int, int> _front = aryRelative.front();
			aryRelative.pop();
			int _r2 = _front.first;
			int _c2 = _front.second;

			for (int i = 0; i < directionR.size(); i++){
				int _r1 = _r2 + directionR[i];
				int _c1 = _c2 + directionC[i];
				if (!checkInRange(_r1, 0, _R) || !checkInRange(_c1, 0, _C)) {
					continue;
				}
				int _p1 = _r1*_C + _c1;
				if (aryFound[_p1]) {
					continue;
				}
				aryFound[_p1] = true;
				if (_map[_r1][_c1] != _map[_r][_c]) {
					continue;
				}
				aryRet.push_back(_p1);
				aryRelative.push(make_pair(_r1, _c1));
			}
		}
		return aryRet;
	}
}