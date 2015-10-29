
#include "Factory.h"
#include "GameRes.h"
#include "base\ccUtils.h"

using namespace cocos2d;

EventListenerTouchOneByOne* Factory::createTouchListener(Node* target
	, std::function<void(Touch*, Event*)>onBegan
	, std::function<void(Touch*, Event*)>onMoved
	, std::function<void(Touch*, Event*)>onEnded
	, std::function<void(Touch*, Event*)>onCancelled) {
	if (!target) {
		return nullptr;
	}
	EventListenerTouchOneByOne* _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = [target, onBegan](Touch* _touch, Event* _event) ->bool {
		Rect _rect = utils::getCascadeBoundingBox(target);
		Vec2 _touchP = _touch->getLocation();
		if (_rect.containsPoint(_touchP)) {
			if (onBegan) {
				onBegan(_touch, _event);
			}
			return true;
		}
		else {
			return false;
		}
	};
	_touchListener->onTouchMoved = [onMoved](Touch* _touch, Event* _event) {
		if (onMoved) {
			onMoved(_touch, _event);
		}
	};
	_touchListener->onTouchCancelled = [onCancelled](Touch* _touch, Event* _event) {
		if (onCancelled) {
			onCancelled(_touch, _event);
		}
	};
	_touchListener->onTouchEnded = [target, onEnded](Touch* _touch, Event* _event) {
		Rect _rect = utils::getCascadeBoundingBox(target);
		Vec2 _touchP = _touch->getLocation(); 
		if (_rect.containsPoint(_touchP) && onEnded) {
			onEnded(_touch, _event);
		}
		else
		{
			onEnded(nullptr, nullptr);
		}
	};
	EventDispatcher* _dispatcher = Director::getInstance()->getEventDispatcher();
	_dispatcher->addEventListenerWithSceneGraphPriority(_touchListener, target);
	return _touchListener;
}

Color3B Factory::getC3BByType(int _type) {
	if (_type == 0) {
		return Color3B(68, 191, 255);
	}
	else if (_type == 1) {
		return Color3B(97, 200, 26);
	}
	else if (_type == 2) {
		return Color3B(190, 60, 255);
	}
	else if (_type == 3) {
		return Color3B(225, 66, 204);
	}
	else if (_type == 4) {
		return Color3B(255, 184, 12);
	}
	else {
		return Color3B(100, 100, 100);
	}
}

// ±¬Õ¨Ð§¹û
ParticleSystemQuad* Factory::getBombAni(int _type) {
	ParticleSystemQuad* _emitter = ParticleSystemQuad::create(GameRes::sParStarBomb);
	Color3B _c3b = Factory::getC3BByType(_type);
	_emitter->setStartColor(Color4F(_c3b));
	_emitter->setEndColor(Color4F(_c3b));
	_emitter->setAutoRemoveOnFinish(true);

	return _emitter;
}