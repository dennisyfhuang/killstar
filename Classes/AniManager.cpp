
#include "AniManager.h"
#include "GameRes.h"
#include "Factory.h"
#include <string>

USING_NS_CC;

static AniManager* g_sharedInstance;

AniManager::AniManager()
{
}

AniManager::~AniManager()
{
}

AniManager* AniManager::getInstance() {
	if (!g_sharedInstance) {
		g_sharedInstance = new AniManager();
	}
	return g_sharedInstance;
}
