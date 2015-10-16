
#ifndef __GLOBALVAR_H__
#define __GLOBALVAR_H__

#include "cocos2d.h"
#include "MusicPlayer.h"
USING_NS_CC;

class GlobalVar
{
public:
	GlobalVar();
	~GlobalVar();

	static GlobalVar* getInstance();

	Size g_winSize;
	Size g_visibleSize;
	Vec2 g_originPoint;

	EventDispatcher* g_eventDispatcher;
	MusicPlayer* g_sharedMusicPlayer;

private:

};

#endif //__GLOBALVAR_H__