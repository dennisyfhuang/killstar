
#ifndef __PLAYGAMEPOPVIEW_H__
#define __PLAYGAMEPOPVIEW_H__

#include "cocos2d.h"

class PlayGamePopView : public cocos2d::Node {
public:
	PlayGamePopView(){};
	~PlayGamePopView(){};
	bool init();
	CREATE_FUNC(PlayGamePopView);

private:
	cocos2d::Node* m_rootUI;
};


#endif //__PLAYGAMEPOPVIEW_H__