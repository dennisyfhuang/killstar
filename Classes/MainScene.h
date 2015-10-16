
#ifndef __MAINSCENE_H__
#define __MAINSCENE_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include <array>
#include "GameRes.h"

class GameController;
class Star;
class MusicPlayer;

class MainScene : public cocos2d::Layer {
public:
	MainScene();
	~MainScene();
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(MainScene);
public:
};

#endif // __MAINSCENE_H__