
#include "GameView.h"
#include "DispatcherEnum.h"
#include "GameRes.h"
#include "Star.h"
#include "GlobalHeader.h"
#include "AniManager.h"
#include "Factory.h"
#include <cmath>
using namespace cocos2d;
using namespace cocostudio;

GameView::GameView() {
	m_starLayer = nullptr;
	m_eventDispatcher = nullptr;
	m_eventList.clear();
	m_starTagList.fill(-1);
	m_mapCopy = nullptr;
	m_aniLayer = nullptr;
	m_eventDispatcher = Director::getInstance()->getEventDispatcher();

	m_iScoreLast = 0;
	m_iScoreStep = 0;
	m_iScoreCur = 0;
	m_bIsScheduleScore = false;
}
GameView::~GameView() {

}

bool GameView::init() {
	if (!Node::init()) {
		return false;
	}
	bool bRet = false;

	do {
		m_starLayer = Node::create();
		m_starLayer->setPositionY(100);
		this->addChild(m_starLayer);
		m_aniLayer = Node::create();
		m_aniLayer->setPositionY(100);
		this->addChild(m_aniLayer, 100);



		initGlobalEvent();
		initUI();

		bRet = true;
	} while (0);

	return bRet;
}

void GameView::initGlobalEvent() {
}

void GameView::initUI() {
	m_rootUI = CSLoader::createNode(GameRes::sGameCsb);
	this->addChild(m_rootUI);

	m_txtGoal = dynamic_cast<ui::Text*>(m_rootUI->getChildByName(NAME_TXT_GOAL));
	m_txtBest = dynamic_cast<ui::Text*>(m_rootUI->getChildByTag(TAG_TXT_BEST));
	m_txtLevel = dynamic_cast<ui::Text*>(m_rootUI->getChildByTag(TAG_TXT_LEVEL));
	m_txtScore = dynamic_cast<ui::Text*>(m_rootUI->getChildByTag(TAG_TXT_NOW));
}

void GameView::setLevel(int _level) {
	m_iLevel = _level;
	__String* _str = __String::createWithFormat("%d", _level);
	m_txtLevel->setString(_str->getCString());
}
void GameView::setScoreCur(int _cur) {
	m_iScoreCur = _cur;
	__String* _str = __String::createWithFormat("%d", _cur);
	m_txtScore->setString(_str->getCString());
}
void GameView::setScoreGoal(int _goal) {
	m_iScoreGoal = _goal;
	__String* _str = __String::createWithFormat("%d", _goal);
	m_txtGoal->setString(_str->getCString());
}
void GameView::ready() {
	m_starLayer->removeAllChildren();
	m_starTagList.fill(-1);
}

void GameView::start() {

	setStar();
}

void GameView::runStartAnimation() {
	Label* _lblLevel = Label::create("关数", "Arial", 30);
	_lblLevel->setAnchorPoint(Vec2(0.5, 1));
	Label* _txtLevel = Label::create("0", "Arial", 30);
	_txtLevel->setAnchorPoint(Vec2(0.5, 0));
	Label* _lblGoal = Label::create("目标分数", "Arial", 30);
	_lblGoal->setAnchorPoint(Vec2(0.5, 1));
	Label* _txtGoal = Label::create("2000", "Arial", 30);
	_txtGoal->setAnchorPoint(Vec2(0.5, 0));

}

void GameView::setStarMap(std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums>& _map) {
	m_mapCopy = &_map;
}

void GameView::setStar() {
	for (int i = 0; i < GameRes::iStarRowNums; i++) {
		for (int j = 0; j < GameRes::iStarColumnNums; j++) {
			Star* _star = Star::create((*m_mapCopy)[i][j], i, j);
			_star->setPosition(Vec2((j + 0.5)*GameRes::iStarWidth, (i + 0.5)*GameRes::iStarHeight));
			m_starLayer->addChild(_star, ZORDER_STAR, i*GameRes::iStarColumnNums + j);
			m_starTagList[i*GameRes::iStarColumnNums + j] = i*GameRes::iStarColumnNums + j;
		}
	}
}

void GameView::setStar(std::array<std::array<int, GameRes::iStarRowNums>, GameRes::iStarColumnNums>& _map) {
	setStarMap(_map);
	setStar();
}

void GameView::willRemoved(std::vector<int> _will) {
	double _delay = 0;
	int n = 0;

	for each(int var in _will) {
		int _r = var / GameRes::iStarColumnNums;
		int _c = var % GameRes::iStarColumnNums;
		Star* _star = dynamic_cast<Star*>(m_starLayer->getChildByTag(m_starTagList[var]));
		_star->showSelected();

		_delay += 0.1;
		gotoRemoved(_star, _delay, n);
		n++;
	}
	this->runAction(Sequence::createWithTwoActions(
		DelayTime::create(_delay + 0.1),
		CallFunc::create([&]{
		m_eventDispatcher->dispatchCustomEvent(CCMD::ADJUST_MAP_C);
	})
		));
}

void GameView::gotoRemoved(Star* _star, double _delay, int _n) {
	_star->runAction(Sequence::createWithTwoActions(
		DelayTime::create(_delay)
		, CallFunc::create([&, _star, _n](){
			GlobalVar::getInstance()->g_sharedMusicPlayer->playEffect(GameRes::EffectCommon);

			int _last = getScoreLast();
			_last += _n * 10 + 5;
			int _step = ceil(_last / 10.0);
			setScoreLast(_last);
			setScoreStep(_step);

			this->scheduleScore();
			Vec2 _p = _star->getPosition();
			auto _bomb = Factory::getBombAni(_star->getType());
			_bomb->setPosition(_p);
			m_aniLayer->addChild(_bomb);

			_star->removeFromParent();
	})
		));
}

int GameView::adjustMap(std::vector<std::pair<int, int>> _will) {
	int n = 0;
	int _R = -1;
	int _delay = 0;
	for each(std::pair<int, int> _pair in _will) {
		int src = _pair.first;
		int dest = _pair.second;

		int _r = dest / GameRes::iStarColumnNums;
		int _c = dest%GameRes::iStarColumnNums;

		if (_R == _r) {
			n++;
		}
		else {
			n = 0;
		}

		Star* _star = dynamic_cast<Star*>(m_starLayer->getChildByTag(m_starTagList[src]));
		m_starTagList[dest] = m_starTagList[src];
		m_starTagList[src] = -1;
		_star->setRow(_r);
		_star->setColumn(_c);
		_star->runAction(Sequence::createWithTwoActions(
			DelayTime::create(n*0.01),
			MoveTo::create(0.03, Vec2((_c + 0.5)*GameRes::iStarWidth, (_r + 0.5)*GameRes::iStarHeight))));
		//_delay = max(_delay, n*0.05);
	}
	return n*0.01 + 0.03;
}
void GameView::adjustMapC(std::vector<std::pair<int, int>> _will) {
	int _delay = adjustMap(_will);
	this->runAction(Sequence::createWithTwoActions(
		DelayTime::create(_delay),
		CallFunc::create([&]{
		m_eventDispatcher->dispatchCustomEvent(CCMD::ADJUST_MAP_R);
	})
		));

}

void GameView::adjustMapR(std::vector<std::pair<int, int>> _will) {
	int _delay = adjustMap(_will);
	this->runAction(Sequence::createWithTwoActions(
		DelayTime::create(_delay),
		CallFunc::create([&]{
		m_starLayer
		m_eventDispatcher->dispatchCustomEvent(CCMD::JUDGE_GAME_OVER);
	})
		));
}

void GameView::scheduleScore() {
	if (getIsScheduleScore()) return;
	setIsScheduleScore(true);
	this->schedule([=](float _dt) {
		int _cur = m_iScoreCur;
		_cur += getScoreStep();
		int _last = getScoreLast() - getScoreStep();
		if (_last < getScoreStep()) {
			setScoreStep(_last);
		}
		setScoreLast(_last);
		setScoreCur(_cur);
		if (_last <= 0) {
			unscheduleScore();
		}
	}, KEY_SCHEDULE_SCORE);
}
void GameView::unscheduleScore() {
	setIsScheduleScore(false);
	this->unschedule(KEY_SCHEDULE_SCORE);
}