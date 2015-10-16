
#include "SceneController.h"
#include "MainController.h"
#include "GameController.h"
#include "MainView.h"
#include "GameView.h"
#include "PlayGamePopView.h"
#include "DispatcherEnum.h"
USING_NS_CC;

static SceneController* m_sharedInstance;

SceneController::SceneController() {
	m_viewNameList.clear();
	m_controlList.clear();
	m_controlNameList.clear();
	m_eventDispatcher = Director::getInstance()->getEventDispatcher();
}
SceneController::~SceneController() {

}
void SceneController::setParentLayer(Node* _self) {
	m_selfLayer = _self;

	m_mainLayer = Node::create();
	m_selfLayer->addChild(m_mainLayer);

	m_gameLayer = Node::create();
	m_selfLayer->addChild(m_gameLayer);
}

SceneController* SceneController::getInstance() {
	if (!m_sharedInstance) {
		m_sharedInstance = new SceneController();
	}
	return m_sharedInstance;
}

void SceneController::initGlobalEvent() {

}

Node* SceneController::viewIntoScene(std::string _viewname, bool _remove, bool _removeAll) {
	Node* _view = nullptr;
	if (_viewname == "main") {
		_view = MainView::create();
		m_mainLayer->addChild(_view);
	}
	else if (_viewname == "game") {
		_view = GameView::create();
		m_gameLayer->addChild(_view);
	}
	else if (_viewname == "playGamePopView") {
		_view = PlayGamePopView::create();
		m_mainLayer->addChild(_view);
	}
	else {
		return nullptr;
	}

	CCLOG("""## = %d", _remove);
	if (_remove && !m_viewNameList.empty()) {
		std::string _last = m_viewNameList.back();
		m_viewNameList.pop_back();

		CCLOG("""## = %s", _last.c_str());
		dispatchRemoveEvent(_last);
	}
	m_viewNameList.push_back(_viewname);
	return _view;
}

Ref* SceneController::createController(std::string _controlname) {
	if (!m_controlNameList.empty()) {
		for (int i = 0; i < m_controlNameList.size(); i++) {
			if (m_controlNameList[i] == _controlname) {
				return m_controlList[i];
			}
		}
	}
	Ref* _control = nullptr;
	if (_controlname == "main") {
		_control = new MainController(m_mainLayer);
	}
	else if (_controlname == "game") {
		_control = new GameController(m_gameLayer);
	}
	else {
		return nullptr;
	}
	m_controlList.push_back(_control);
	m_controlNameList.push_back(_controlname);
	return _control;
}

void SceneController::dispatchRemoveEvent(std::string _name) {
	std::string _viewname = "";
	if (_name == "main") {
		_viewname = CCMD::REMOVE_VIEW_MAIN;
	}
	else if (_name == "game") {
		_viewname = CCMD::REMOVE_VIEW_GAME;
	}
	else {
		return;
	}
	CCLOG("""## = %s", _name.c_str());
	m_eventDispatcher->dispatchCustomEvent(_viewname, &_name);
}