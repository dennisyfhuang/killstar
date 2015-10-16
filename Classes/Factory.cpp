
#include "Factory.h"
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
