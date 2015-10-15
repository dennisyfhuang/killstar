
#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__

#include "cocos2d.h"
#include <vector>
#include <array>
#include "GameRes.h"

class GameView;

class GameController : public cocos2d::Ref {
#define TAG_GAME_VIEW 1001

public:
	GameController(cocos2d::Node*);
	~GameController();

	bool init();

	void initGlobalEvent();
	void removeGlobalEvent();

	void findRelativeStar(cocos2d::EventCustom* _custom);
	void initMap();
	void adjustMapC(); // 纵向调整星星
	void adjustMapR(); // 横向调整星星
	void ready();
	void start();
	// 判断（_r,_c）的星星可否消除
	bool judgeCanRemoved(int _r, int _c, int _n);
	// 判断本轮是否结束
	bool judgeGameOverThis();
	// 判断游戏是否结束
	void judgeGameOver();
	// 计算_c列是否可以消除
	void calCanRemoved(int _c);

	void initView();
	void createView(std::string _viewname);

	std::vector<std::string> m_eventList;

	// 将要删除的星星；
	std::vector<int> m_willRemoved;
	// 将要移动的星星
	std::vector<std::pair<int, int>> m_willMoved;
	// 标记空的列
	std::array<bool, GameRes::iStarColumnNums> m_emptyColumn;
	// 标记一列中的星星可否继续消除
	std::array<bool, GameRes::iStarColumnNums> m_canRemoved;

	cocos2d::EventDispatcher* m_eventDispatcher;
	// 标记是否游戏结束
	bool m_bGameOver;
	// 标记本局是否结束
	bool m_bGameOverThis;

	// 当前得分
	int m_iScoreCur;
	// 目标分数
	int m_iScoreGoal;
	// 当前关
	int m_iLevel;

private:
	std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums> m_map;
	std::vector<cocos2d::Node*> m_viewList;
	cocos2d::Node* m_selfLayer;
};



#endif // __GAMECONTROLLER_H__