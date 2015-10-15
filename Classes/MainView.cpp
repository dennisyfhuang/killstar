
#include "SceneController.h"
#include "GameController.h"
#include "MainView.h"
#include "GameRes.h"


MainView::MainView() {
}
MainView::~MainView() {

}

bool MainView::init() {
	if (!Node::init()) {
		return false;
	}
	bool bRet = false;

	do {
		auto root = CSLoader::createNode(GameRes::sMainCsb);
		m_panMain = root->getChildByName("pan_main");
		this->addChild(root);

		m_btnPlay = dynamic_cast<ui::Button*>(m_panMain->getChildByTag(TAG_BTN_PLAY));
		m_btnShop = dynamic_cast<ui::Button*>(m_panMain->getChildByTag(TAG_BTN_SHOP));
		m_btnRecord = dynamic_cast<ui::Button*>(m_panMain->getChildByTag(TAG_BTN_RECORD));

		initBtnClick();
		initLight();
		bRet = true;
	} while (0);

	return bRet;
}

void MainView::initBtnClick() {
	m_btnPlay->addClickEventListener([=](Ref* sender){
		if (!UserDefault::getInstance()->getBoolForKey("bGameOver", true)) {
			auto _control = dynamic_cast<GameController*>(SceneController::getInstance()->createController("main"));
			_control->createView("playGamePopView");
		}
		else {
			auto _control = dynamic_cast<GameController*>(SceneController::getInstance()->createController("game"));
			_control->createView("game");
		}
	});
	m_btnShop->addClickEventListener([=](Ref* sender){
		CCLOG("yyuuuuuuu 0");
	});
	m_btnRecord->addClickEventListener([=](Ref* sender){
		CCLOG("yyuuuuuuu 1");
	});
}

void MainView::initLight() {
	Sprite* _blue = dynamic_cast<Sprite*>(m_panMain->getChildByName(NAME_SPRITE_BLUE));
	_blue->setOpacity(0);
	_blue->runAction(RepeatForever::create(Sequence::create(
		DelayTime::create(0.5)
		, FadeIn::create(1.2)
		, FadeOut::create(1.2)
		, nullptr)));
	Sprite* _red = dynamic_cast<Sprite*>(m_panMain->getChildByName(NAME_SPRITE_RED));
	_red->setOpacity(0);
	_red->runAction(RepeatForever::create(Sequence::create(
		DelayTime::create(1.0)
		, FadeIn::create(1.0)
		, FadeOut::create(1.0)
		, nullptr)));
	Sprite* _pink = dynamic_cast<Sprite*>(m_panMain->getChildByName(NAME_SPRITE_PINK));
	_pink->setOpacity(0);
	_pink->runAction(RepeatForever::create(Sequence::create(
		DelayTime::create(0.8)
		, FadeIn::create(1.5)
		, FadeOut::create(1.5)
		, nullptr)));
	Sprite* _green = dynamic_cast<Sprite*>(m_panMain->getChildByName(NAME_SPRITE_GREEN));
	_green->setOpacity(0);
	_green->runAction(RepeatForever::create(Sequence::create(
		DelayTime::create(1.0)
		, FadeIn::create(2.5)
		, FadeOut::create(1.5)
		, nullptr)));
	Sprite* _yellow = dynamic_cast<Sprite*>(m_panMain->getChildByName(NAME_SPRITE_YELLOW));
	_yellow->setOpacity(0);
	_yellow->runAction(RepeatForever::create(Sequence::create(
		DelayTime::create(1.5)
		, FadeIn::create(1.5)
		, FadeOut::create(2.0)
		, nullptr)));
}