
#ifndef __MAINVIEW_H__
#define __MAINVIEW_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

using namespace cocostudio;
using namespace cocos2d;

class MainView : public cocos2d::Node {
#define TAG_IMG_SHOP 24
#define TAG_BTN_SHOP 26
#define TAG_BTN_PLAY 25
#define TAG_BTN_RECORD 27
#define TAG_LBL_LEVEL 22
#define TAG_LBL_BEST_SCORE 2

#define NAME_IMG_SHOP "lbl_shop_num"
#define NAME_BTN_SHOP "btn_shop"
#define NAME_BTN_PLAY "btn_play"
#define NAME_BTN_RECORD "btn_record"
#define NAME_LBL_LEVEL "lbl_level"
#define NAME_LBL_BEST_SCORE "lbl_bestScore"

#define NAME_SPRITE_BLUE "sp_blue"
#define NAME_SPRITE_RED "sp_red"
#define NAME_SPRITE_PINK "sp_pink"
#define NAME_SPRITE_GREEN "sp_green"
#define NAME_SPRITE_YELLOW "sp_yellow"

public:
	MainView();
	~MainView();
	bool init();
	CREATE_FUNC(MainView);

	void initBtnClick();
	void initLight();
private:
	ui::Button* m_btnPlay;
	ui::Button* m_btnShop;
	ui::Button* m_btnRecord;
	cocos2d::Node* m_panMain;
};


#endif //__MAINVIEW_H__