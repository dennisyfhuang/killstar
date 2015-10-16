
#include "Star.h"
#include "GameRes.h"
#include "Factory.h"
#include "DispatcherEnum.h"
#include "array"

Star::Star() {
	m_sprite = nullptr;
	m_spriteSelected = nullptr;
	m_touchListener = nullptr;
	m_eventDispatcher = Director::getInstance()->getEventDispatcher();
}

Star* Star::create(std::string filename, int iRow, int iColumn) {
	int _type = 0;
	for (int k = 0; k < GameRes::iStarPathNums; k++) {
		if (GameRes::sStarPath[k] == filename) {
			_type = k;
			break;
		}
	}
	return Star::create(_type, iRow, iColumn);
}

Star* Star::create(int iType, int iRow, int iColumn) {
	Star* _star = new(std::nothrow) Star();
	if (_star && _star->init(iType, iRow, iColumn)) {
		_star->autorelease();
		return _star;
	}
	else {
		CC_SAFE_DELETE(_star);
		return nullptr;
	}
}

bool Star::init(int iType, int iRow, int iColumn) {
	if (!Node::init()) {
		return false;
	}

	bool bRet = false;
	do {
		using namespace GameRes;
		CC_BREAK_IF(iType >= iStarPathNums || iType < 0);
		m_sprite = Sprite::create(sStarPath[iType]);
		CC_BREAK_IF(!m_sprite);
		this->addChild(m_sprite);
		this->initTouchListen();

		this->setType(iType);
		this->setRow(iRow);
		this->setColumn(iColumn);
		bRet = true;
	} while (0);

	return bRet;
}

Sprite* Star::getSprite() {
	return m_sprite;
}

void Star::initTouchListen() {
	std::function<void(Touch*, Event*)> onBegan = [&](Touch* _touch, Event* _event){
		this->touchBeganAction();
	};
	std::function<void(Touch*, Event*)> onEnded = [&](Touch* _touch, Event* _event){
		this->touchEndedAction();
		if (_touch && _event) {
			std::array<int, 2> _data = { getRow(), getColumn() };
			m_eventDispatcher->dispatchCustomEvent(CCMD::AI, &_data);
		}
	};
	m_touchListener = Factory::createTouchListener(this
		, onBegan, nullptr, onEnded, onEnded);
}

void Star::touchBeganAction() {
	this->stopAllActions();
	this->setScale(1.0);
	this->runAction(EaseBounceOut::create(ScaleTo::create(0.1, 0.9)));
}

void Star::touchEndedAction() {
	this->stopAllActions();
	this->setScale(1.0);
}

void Star::showSelected() {
	if (!m_spriteSelected) {
		m_spriteSelected = Sprite::create(GameRes::sStarSelected);
		this->addChild(m_spriteSelected);
	}
	else {
		m_spriteSelected->setVisible(true);
	}
}

void Star::hideSelected(){
	if (!m_spriteSelected) {
		return;
	}
	else {
		m_spriteSelected->setVisible(false);
	}
}
