
#ifndef __SCENECONTROLLER_H__
#define __SCENECONTROLLER_H__

#include "cocos2d.h"
#include <vector>

class SceneController : public cocos2d::Ref {
#define concatVar(v1,v2) v1##v2
public:
	SceneController();
	~SceneController();
	static SceneController* getInstance();

	void initGlobalEvent();
	void dispatchRemoveEvent(std::string _name);
	void setParentLayer(cocos2d::Node*);
	
	cocos2d::Node* viewIntoScene(std::string _viewname, bool _remove = true, bool _removeAll = false);

	cocos2d::Ref* createController(std::string _controlname);

private:
	cocos2d::EventDispatcher* m_eventDispatcher;

	std::vector<std::string> m_viewNameList;
	std::vector<cocos2d::Ref*> m_controlList;
	std::vector<std::string> m_controlNameList;

	cocos2d::Node* m_selfLayer;
	cocos2d::Node* m_mainLayer;
	cocos2d::Node* m_gameLayer;
};


#endif // __SCENECONTROLLER_H__