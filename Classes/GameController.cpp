
#include "GameController.h"
#include "SceneController.h"
#include "DispatcherEnum.h"
#include "array"
#include "AI.h"
#include "GameRes.h"
#include "GameView.h"
#include "ScoreConfig.h"
using namespace cocos2d;

GameController::GameController(Node* _self) {
	m_selfLayer = _self;
	m_eventList.clear();
	m_viewList.clear();
	m_eventDispatcher = Director::getInstance()->getEventDispatcher();
	m_iScoreCur = 0;
	m_iLevel = 0;
	m_iScoreGoal = g_scoreConfig[m_iLevel];
	init();
}

GameController::~GameController() {
	removeGlobalEvent();
}

bool GameController::init() {
	bool bRet = false;

	do {
		m_iScoreCur = 0;
		initGlobalEvent();
		initView();
		bRet = true;
	} while (0);

	return bRet;
}

void GameController::initView() {
}

void GameController::createView(std::string _viewname) {
	if (_viewname == "game") {
		if (!m_selfLayer->getChildByTag(TAG_GAME_VIEW)) {
			auto _gameView = dynamic_cast<GameView*>(SceneController::getInstance()->viewIntoScene("game")); //GameView::create();
			_gameView->setTag(TAG_GAME_VIEW);
			m_viewList.push_back(_gameView);

			ready();
			start();
		}
	}
}

void GameController::ready() {
	m_bGameOver = UserDefault::getInstance()->getBoolForKey("bGameOver", false);
	m_bGameOverThis = UserDefault::getInstance()->getBoolForKey("bGameOverThis", false);
	m_iLevel = UserDefault::getInstance()->getIntegerForKey("iLevel", 1);
	m_iScoreGoal = g_scoreConfig[m_iLevel];
	m_iScoreCur = UserDefault::getInstance()->getIntegerForKey("iScoreCur", 0);
	m_willRemoved.clear();
	m_willMovedC.clear();
	m_willMovedR.clear();
	m_emptyColumn.fill(false);
	m_canRemoved.fill(false);
	initMap();

	auto _gameView = dynamic_cast<GameView*>(m_selfLayer->getChildByTag(TAG_GAME_VIEW));
	_gameView->ready();

	_gameView->setLevel(m_iLevel);
	_gameView->setScoreCur(m_iScoreCur);
	_gameView->setScoreGoal(m_iScoreGoal);

	_gameView->setStarMap(m_map);
}

void GameController::start() {
	auto _gameView = dynamic_cast<GameView*>(m_selfLayer->getChildByTag(TAG_GAME_VIEW));
	_gameView->start();
}

bool GameController::judgeCanRemoved(int _r, int _c, int _n){
	if (m_map[_r][_c] == -1) {
		return false;
	}
	if (_n == 1) { // ���
		if (_c > 0 && m_map[_r][_c] == m_map[_r][_c - 1])
			return true;
	}
	else if (_n == 2) { //�ϱ�
		if (_r < GameRes::iStarRowNums - 1 && m_map[_r][_c] == m_map[_r + 1][_c])
			return true;
	}
	else if (_n == 3) { // �ұ�
		if (_c < GameRes::iStarColumnNums - 1 && m_map[_r][_r] == m_map[_r][_c + 1])
			return true;
	}
	else if (_n == 4) { // �±�
		if (_r > 0 && m_map[_r][_c] == m_map[_r - 1][_c])
			return true;
	}
	return false;
}

void GameController::calCanRemoved(int _c) {
	m_canRemoved[_c] = false;
	for (int _r = 0; _r < GameRes::iStarRowNums; _r++) {
		m_canRemoved[_c] = m_canRemoved[_c] || judgeCanRemoved(_r, _c, 1) || judgeCanRemoved(_r, _c, 2);
		if (m_canRemoved[_c]) {
			return;
		}
	}
}

void GameController::initMap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int iType = random() % 5;
			m_map[i][j] = iType;
		}
	}

	saveMap();
	UserDefault::getInstance()->setBoolForKey("bGameOver", m_bGameOver);
	UserDefault::getInstance()->setBoolForKey("bGameOverThis", m_bGameOverThis);

	for (int j = 0; j < GameRes::iStarColumnNums; j++) {
		calCanRemoved(j);
	}
}

void GameController::saveMap() {
	if (m_bGameOver) {
		return;
	}
	std::string _writeName = FileUtils::getInstance()->getWritablePath();
	_writeName += "savemap.txt";
	std::string _map = "";
	__String* _temp = nullptr;
	for (int i = 0; i < GameRes::iStarRowNums; i++) {
		for (int j = 0; j < GameRes::iStarColumnNums; j++) {
			_temp = __String::createWithFormat("%d", m_map[i][j]) + i*j - i - j;
			_map += _temp->getCString();
			_map += ";";
		}
	}
	FileUtils::getInstance()->writeStringToFile(_map.c_str(), _writeName);
}

void GameController::initGlobalEvent() {
	m_eventList.push_back(CCMD::AI);
	m_eventDispatcher->addCustomEventListener(CCMD::AI, CC_CALLBACK_1(GameController::findRelativeStar, this));
	m_eventList.push_back(CCMD::ADJUST_MAP_C);
	m_eventDispatcher->addCustomEventListener(CCMD::ADJUST_MAP_C, CC_CALLBACK_0(GameController::adjustMapC, this));
	m_eventList.push_back(CCMD::ADJUST_MAP_R);
	m_eventDispatcher->addCustomEventListener(CCMD::ADJUST_MAP_R, CC_CALLBACK_0(GameController::adjustMapR, this));
	m_eventList.push_back(CCMD::JUDGE_GAME_OVER);
	m_eventDispatcher->addCustomEventListener(CCMD::JUDGE_GAME_OVER, CC_CALLBACK_0(GameController::judgeGameOver, this));
}
void GameController::removeGlobalEvent() {
	for each(std::string var in m_eventList) {
		m_eventDispatcher->removeCustomEventListeners(var);
	}
	m_eventList.clear();
}

void GameController::findRelativeStar(EventCustom* _custom) {
	auto _data = (std::array<int, 2>*)_custom->getUserData();

	m_willRemoved.clear();
	m_willRemoved = AI::findRelativeByQueue(m_map, 10, 10, _data[0][0], _data[0][1]);

	if (m_willRemoved.size() > 1) {
		preadjustMapC(); // Ԥ������
		preadjustMapR(); // Ԥ������

		int n = m_willRemoved.size();
		m_iScoreCur += 5 * n*n;

		saveMap(); // �����ͼ
		judgeGameOver();
		UserDefault::getInstance()->setBoolForKey("bGameOver", m_bGameOver);
		UserDefault::getInstance()->setBoolForKey("bGameOverThis", m_bGameOverThis);
		UserDefault::getInstance()->getBoolForKey("iScoreCur", m_iScoreCur);

		auto _gameView = dynamic_cast<GameView*>(m_selfLayer->getChildByTag(TAG_GAME_VIEW));
		_gameView->willRemoved(m_willRemoved);
	}
}
void GameController::adjustMapC() {
	auto _gameView = dynamic_cast<GameView*>(m_selfLayer->getChildByTag(TAG_GAME_VIEW));
	_gameView->adjustMapC(m_willMovedC);
}
void GameController::preadjustMapC() {
	std::array<bool, GameRes::iStarColumnNums> _adjustC; // ��Ҫ��������
	_adjustC.fill(false);
	for each(int v in m_willRemoved) {
		int _c = v%GameRes::iStarColumnNums;
		m_map[v / GameRes::iStarColumnNums][_c] = -1;
		_adjustC[_c] = true;
	}

	m_willMovedC.clear();
	// �������ƶ�
	for (int i = 0; i < GameRes::iStarColumnNums; i++) {
		if (!_adjustC[i]) { // ����Ҫ����
			m_emptyColumn[i] = false;
			// ��������һ����Ҫ�����������¼����������
			if (i > 0 && _adjustC[i - 1]) {
				calCanRemoved(i);
			}
			continue;
		}
		m_emptyColumn[i] = true;
		int local = -1;
		if (m_map[0][i] == -1) {
			local = 0;
		} 
		for (int j = 1; j < GameRes::iStarRowNums; j++) {
			if (local == -1) {
				m_emptyColumn[i] = false;
				if (m_map[j][i] == -1) {
					local = j;
				}
			}
			else if (m_map[j][i] != -1) {
				m_emptyColumn[i] = false;
				m_map[local][i] = m_map[j][i];
				m_map[j][i] = -1;
				int src = j*GameRes::iStarColumnNums + i;
				int dest = local*GameRes::iStarColumnNums + i;
				m_willMovedC.push_back(std::make_pair(src, dest));
				local++;
			}
		}

		// ���������ٴ��жϴ����Ƿ������ǿ�������
		calCanRemoved(i);
	}
}
void GameController::adjustMapR() {
	auto _gameView = dynamic_cast<GameView*>(m_selfLayer->getChildByTag(TAG_GAME_VIEW));
	_gameView->adjustMapR(m_willMovedR);
}
void GameController::preadjustMapR() {
	m_willMovedR.clear();
	int local = -1;
	if (m_emptyColumn[0]) {
		local = 0;
	}
	for (int _c = 1; _c < GameRes::iStarColumnNums; _c++) {
		if (local == -1) {
			if (m_emptyColumn[_c]) {
				local = _c;
			}
		}
		else if (!m_emptyColumn[_c]) {
			for (int _r = 0; _r < GameRes::iStarRowNums; _r++) {
				// (_r, _c) -> (_r, local)
				if (m_map[_r][_c] == -1) {
					break;
				}
				m_map[_r][local] = m_map[_r][_c];
				m_map[_r][_c] = -1;
				int src = _r*GameRes::iStarColumnNums + _c;
				int dest = _r*GameRes::iStarColumnNums + local;
				m_willMovedR.push_back(std::make_pair(src, dest));
			}

			// ����local��_c���Ƿ������ǿ����Ƴ�
			m_canRemoved[_c] = false;
			calCanRemoved(local);

			local++;
		}
	}

	if (local != -1) {
		for (; local < GameRes::iStarColumnNums; local++) {
			m_canRemoved[local] = false;
		}
	}
}

bool GameController::judgeGameOverThis() {
	m_bGameOverThis = true;
	for (int i = 0; i < GameRes::iStarColumnNums; i++) {
		m_bGameOverThis = m_bGameOverThis && (!m_canRemoved[i]);
	}
	return m_bGameOverThis;
}
// ��Ҫ��judgeGameOverThis()��������֮��ʹ��
void GameController::judgeGameOver() {
	judgeGameOverThis();
	m_bGameOver = m_bGameOverThis && (m_iScoreCur < m_iScoreGoal);
	if (m_bGameOver) { // ��Ϸ����
		ready();
		start();
	}
	else if (m_bGameOverThis) { // ������Ϸ����
		ready();
		start();
	}
}

