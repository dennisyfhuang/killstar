
#include "MainController.h"
#include "SceneController.h"
#include "MainView.h"
#include "DispatcherEnum.h"

USING_NS_CC;

MainController::MainController(Node* _self) {
	m_selfLayer = _self;
	m_eventDispatcher = Director::getInstance()->getEventDispatcher();

	m_playGamePopView = nullptr;
	m_mainView = nullptr;

	init();
}
MainController::~MainController() {

}

bool MainController::init() {
	initGlobalEvent();
	return true;
}

void MainController::initGlobalEvent() {
	m_eventList.push_back(CCMD::REMOVE_VIEW_MAIN);
	m_eventDispatcher->addCustomEventListener(CCMD::REMOVE_VIEW_MAIN, CC_CALLBACK_1(MainController::removeView, this));
}

void MainController::removeGlobalEvent() {

}

void MainController::createView(std::string _viewname) {
	if (_viewname == "main") {
		m_mainView = SceneController::getInstance()->viewIntoScene("main");
	}
	else if (_viewname == "playGamePopView") {
		m_playGamePopView = dynamic_cast<PlayGamePopView*>(SceneController::getInstance()->viewIntoScene("playGamePopView"));
	}
}

void MainController::removeView(EventCustom* _data){
	std::string* _viewname = (std::string*)(_data->getUserData());
	if (*_viewname == "main") {
		m_mainView->removeFromParent();
		m_mainView = nullptr;
	}
	else if (*_viewname == "playGamePopView") {
		m_playGamePopView->removeFromParent();
		m_playGamePopView = nullptr;
	}
}