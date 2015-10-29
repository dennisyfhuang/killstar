
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "cocos2d.h"

class Factory
{
public:
	static cocos2d::EventListenerTouchOneByOne* createTouchListener(cocos2d::Node* target
		, std::function<void(cocos2d::Touch*, cocos2d::Event*)>onBegan
		, std::function<void(cocos2d::Touch*, cocos2d::Event*)>onMoved
		, std::function<void(cocos2d::Touch*, cocos2d::Event*)>onEnded
		, std::function<void(cocos2d::Touch*, cocos2d::Event*)>onCancelled);

	static cocos2d::Color3B getC3BByType(int _type);
	static cocos2d::ParticleSystemQuad* getBombAni(int _type);

private:

};


#endif //__FACTORY_H__