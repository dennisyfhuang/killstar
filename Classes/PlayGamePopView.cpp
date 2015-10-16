
#include "PlayGamePopView.h"
#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
#include "GameRes.h"

using namespace cocostudio;
using namespace cocos2d;

bool PlayGamePopView::init() {
	if (!Node::init()) {
		return false;
	}

	m_rootUI = CSLoader::createNode(GameRes::sPlayGameCsb);
	addChild(m_rootUI);

	return true;
}