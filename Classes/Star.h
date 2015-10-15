
#ifndef __STAR_H__
#define __STAR_H__

#include "cocos2d.h"

using namespace cocos2d;

class Star : public Node
{
public:
	Star();
	static Star* create(std::string filename, int iRow, int iColumn);
	static Star* create(int iType, int iRow, int iColumn);
	bool init(int iType, int iRow, int iColumn);
	void initTouchListen();
	void showSelected();
	void hideSelected();

	CC_SYNTHESIZE(int, m_iColumn, Column);
	CC_SYNTHESIZE(int, m_iRow, Row);
	CC_SYNTHESIZE(int, m_iType, Type);
	CC_SYNTHESIZE(bool, m_bWillMove, WillMove);
	Sprite* getSprite();

	// 触摸开始特效
	void touchBeganAction();
	// 触摸结束特效
	void touchEndedAction();

private:
	Sprite* m_sprite;
	Sprite* m_spriteSelected;
	EventListenerTouchOneByOne* m_touchListener;
	EventDispatcher* m_eventDispatcher;
};


#endif // __STAR_H__