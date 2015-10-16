
#ifndef __GAMEVIEW_H__
#define __GAMEVIEW_H__

#include "cocos2d.h"
#include <array>
#include <vector>
#include "GameRes.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

class Star;
class MusicPlayer;

class GameView : public cocos2d::Node {
#define ZORDER_STAR 10
#define ZORDER_STAR_SELECTED ZORDER_STAR-1

#define ZORDER_STAR_LAYER 1

#define TAG_SCORE 100
#define TAG_SCORE_GOAL 110

#define TAG_LBL_GOAL 13
#define TAG_TXT_GOAL 14
#define NAME_TXT_GOAL "txt_goal"
#define TAG_LBL_LEVEL 4
#define TAG_TXT_LEVEL 6
#define TAG_TXT_BEST 10
#define TAG_TXT_NOW 8

#define KEY_SCHEDULE_SCORE "KEY_SCHEDULE_SCORE"

public:
	GameView();
	~GameView();
	bool init();
	CREATE_FUNC(GameView);

	void initGlobalEvent();
	void initUI();

	void setStarMap(std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums>&);
	void setStar();
	void setStar(std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums>&);

	void ready();
	void start();
	void runStartAnimation();

	void willRemoved(std::vector<int>); // 已经把要删除的星星标记，将要删除星星
	void gotoRemoved(Star* _star, double _delay, int _n); // 删除星星动画
	void adjustMap(std::vector<std::pair<int, int>>); // 调整星星
	void adjustMapC(std::vector<std::pair<int, int>>); // 纵向调整星星
	void adjustMapR(std::vector<std::pair<int, int>>); // 横向调整星星

	void scheduleScore();
	void unscheduleScore();

	void setLevel(int _level);
	void setScoreCur(int _cur);
	void setScoreGoal(int _goal);

	// 用作分数
	CC_SYNTHESIZE(int, m_iScoreLast, ScoreLast);
	CC_SYNTHESIZE(int, m_iScoreStep, ScoreStep);
	CC_SYNTHESIZE(bool, m_bIsScheduleScore, IsScheduleScore);

private:
	cocos2d::Node* m_starLayer;
	cocos2d::Node* m_rootUI;
	cocos2d::EventDispatcher* m_eventDispatcher;
	std::vector<std::string> m_eventList;
	std::array<int, GameRes::iStarNums> m_starTagList;
	std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums>* m_mapCopy;

	cocos2d::ui::Text* m_txtGoal;
	cocos2d::ui::Text* m_txtBest;
	cocos2d::ui::Text* m_txtLevel;
	cocos2d::ui::Text* m_txtScore;
private:
	int m_iLevel;
	int m_iScoreGoal;
	int m_iScoreBest;
	int m_iScoreCur;
};

#endif //__GAMEVIEW_H__