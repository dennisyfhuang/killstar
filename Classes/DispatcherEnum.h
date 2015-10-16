
#ifndef __DISPATCHERENUM_H__
#define __DISPATCHERENUM_H__

#include "string"

namespace CCMD {
	const std::string AI = "CCMD_AI";
	const std::string WILL_REMOVED = "CCMD_WILL_REMOVED";
	const std::string ADJUST_MAP_C = "CCMD_ADJUST_MAP_C"; // 纵向调整地图
	const std::string ADJUST_C_OVER = "CCMD_ADJUST_C_OVER"; // 纵向调整地图完成
	const std::string ADJUST_MAP_R = "CCMD_ADJUST_MAP_R"; // 横向调整地图
	const std::string ADJUST_R_OVER = "CCMD_ADJUST_R_OVER"; // 横向调整地图完成
	const std::string JUDGE_GAME_OVER = "CCMD_JUDGE_GAME_OVER"; // 判断游戏是否结束
	const std::string REMOVE_VIEW_MAIN = "CCMD_REMOVE_VIEW_MAIN"; // 移除主界面MainView
	const std::string REMOVE_VIEW_GAME = "CCMD_REMOVE_VIEW_GAME"; // 移除游戏界面GameView
}

namespace SCMD {

}

#endif //__DISPATCHERENUM_H__