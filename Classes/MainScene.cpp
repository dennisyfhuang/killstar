
#include "MainScene.h"
#include "Star.h"
#include "SceneController.h"
#include "MainController.h"
#include "DispatcherEnum.h"
#include "cstdlib"
#include "GlobalHeader.h"

USING_NS_CC;
using namespace cocos2d::ui;

const int TAG_MAIN_LAYER = 10000;

MainScene::MainScene() {
}

MainScene::~MainScene() {
}

Scene* MainScene::createScene() {
	Scene* mainScene = Scene::create();
	Layer *mainLayer = MainScene::create();

	mainScene->addChild(mainLayer, 0, TAG_MAIN_LAYER);

	return mainScene;
}

bool MainScene::init() {
	if (!Layer::init()) {
		return false;
	}

	GlobalVar* m_globalHeader = GlobalVar::getInstance();
	Sprite* imgBg = Sprite::create(GameRes::sMainSceneBg);
	imgBg->setPosition(Vec2(m_globalHeader->g_winSize.width*0.5, m_globalHeader->g_winSize.height*0.5));
	this->addChild(imgBg);

	auto _sceneController = SceneController::getInstance();
	_sceneController->setParentLayer(this);
	auto _control = dynamic_cast<MainController*>(_sceneController->createController("main"));
	_control->createView("main");
	//m_gameController->autorelease();

	//m_gameController->ready();
	//m_gameController->start();

	return true;
}
