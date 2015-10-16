
#ifndef __DISPATCHERENUM_H__
#define __DISPATCHERENUM_H__

#include "string"

namespace CCMD {
	const std::string AI = "CCMD_AI";
	const std::string WILL_REMOVED = "CCMD_WILL_REMOVED";
	const std::string ADJUST_MAP_C = "CCMD_ADJUST_MAP_C"; // ���������ͼ
	const std::string ADJUST_C_OVER = "CCMD_ADJUST_C_OVER"; // ���������ͼ���
	const std::string ADJUST_MAP_R = "CCMD_ADJUST_MAP_R"; // ���������ͼ
	const std::string ADJUST_R_OVER = "CCMD_ADJUST_R_OVER"; // ���������ͼ���
	const std::string JUDGE_GAME_OVER = "CCMD_JUDGE_GAME_OVER"; // �ж���Ϸ�Ƿ����
	const std::string REMOVE_VIEW_MAIN = "CCMD_REMOVE_VIEW_MAIN"; // �Ƴ�������MainView
	const std::string REMOVE_VIEW_GAME = "CCMD_REMOVE_VIEW_GAME"; // �Ƴ���Ϸ����GameView
}

namespace SCMD {

}

#endif //__DISPATCHERENUM_H__