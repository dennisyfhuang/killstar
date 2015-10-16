
#include "GlobalVar.h"

static GlobalVar* g_sharedInstance = nullptr;

GlobalVar::GlobalVar()
{
	g_winSize = Director::getInstance()->getWinSizeInPixels();
	g_visibleSize = Director::getInstance()->getVisibleSize();
	g_originPoint = Director::getInstance()->getVisibleOrigin();

	g_eventDispatcher = Director::getInstance()->getEventDispatcher();
	g_sharedMusicPlayer = MusicPlayer::getInstance();
}

GlobalVar::~GlobalVar()
{
}

GlobalVar* GlobalVar::getInstance()
{
	if (!g_sharedInstance) {
		g_sharedInstance = new (std::nothrow) GlobalVar();
	}
	return g_sharedInstance;
}