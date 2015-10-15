
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
	void adjustMapC(); // �����������
	void adjustMapR(); // �����������
	void ready();
	void start();
	// �жϣ�_r,_c�������ǿɷ�����
	bool judgeCanRemoved(int _r, int _c, int _n);
	// �жϱ����Ƿ����
	bool judgeGameOverThis();
	// �ж���Ϸ�Ƿ����
	void judgeGameOver();
	// ����_c���Ƿ��������
	void calCanRemoved(int _c);

	void initView();
	void createView(std::string _viewname);

	std::vector<std::string> m_eventList;

	// ��Ҫɾ�������ǣ�
	std::vector<int> m_willRemoved;
	// ��Ҫ�ƶ�������
	std::vector<std::pair<int, int>> m_willMoved;
	// ��ǿյ���
	std::array<bool, GameRes::iStarColumnNums> m_emptyColumn;
	// ���һ���е����ǿɷ��������
	std::array<bool, GameRes::iStarColumnNums> m_canRemoved;

	cocos2d::EventDispatcher* m_eventDispatcher;
	// ����Ƿ���Ϸ����
	bool m_bGameOver;
	// ��Ǳ����Ƿ����
	bool m_bGameOverThis;

	// ��ǰ�÷�
	int m_iScoreCur;
	// Ŀ�����
	int m_iScoreGoal;
	// ��ǰ��
	int m_iLevel;

private:
	std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums> m_map;
	std::vector<cocos2d::Node*> m_viewList;
	cocos2d::Node* m_selfLayer;
};



#endif // __GAMECONTROLLER_H__