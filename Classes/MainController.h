
#ifndef __MAINCONTROLLER_H__
#define __MAINCONTROLLER_H__

#include "cocos2d.h"
#include <vector>
#include "PlayGamePopView.h"

class MainController : public cocos2d::Ref {
public:
	MainController(cocos2d::Node*);
	~MainController();
	bool init();
	void initGlobalEvent();
	void removeGlobalEvent();

	void removeView(cocos2d::EventCustom* _data);
	void createView(std::string _viewname);

	cocos2d::EventDispatcher* m_eventDispatcher;
private:
	std::vector<std::string> m_eventList;
	cocos2d::Node* m_selfLayer;
	cocos2d::Node* m_mainView;
	PlayGamePopView* m_playGamePopView;
};


#endif //__MAINCONTROLLER_H__