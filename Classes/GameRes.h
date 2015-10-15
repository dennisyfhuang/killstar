
#ifndef __GAMERES_H__
#define __GAMERES_H__

#include "string"

namespace GameRes {
	const std::string sStarPath[5] = {
		"star/block_blue.png" //��ɫ
		, "star/block_green.png" // ��ɫ
		, "star/block_purple.png" // ��ɫ
		, "star/block_red.png" //��ɫ
		, "star/block_yellow.png" // ��ɫ
	};
	const std::string sStarSelected = "star/block_select.png";
	const std::string sMainSceneBg = "bg_mainscene.png";

	const std::string sMainCsb = "main.csb";
	const std::string sGameCsb = "game.csb";
	const std::string sPlayGame = "play_game.csb";
	const std::string sGameOver = "game_over.csb";
	const std::string sSetting = "setting.csb";

	const int iStarPathNums = 5;
	const int iStarWidth = 64;
	const int iStarHeight = 64;
	const int iStarRealWidth = 64;
	const int iStarRealHeight = 64;
	const int iStarRowNums = 10;
	const int iStarColumnNums = 10;
	const int iStarNums = iStarRowNums*iStarColumnNums;

	const std::string GameMusic = "sound/battle_bgm.mp3";
	const std::string EffectCommon = "sound/effect_common.mp3";
}

#endif // __GAMERES_H__