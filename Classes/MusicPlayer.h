
#ifndef __MUSICPLAYER_H__
#define __MUSICPLAYER_H__ 

#include <string>
#include "cocos2d.h"
#include "audio\include\AudioEngine.h"

class MusicPlayer {
public:
	MusicPlayer();
	~MusicPlayer();
	static MusicPlayer* getInstance();
	void playMusic(std::string filename);
	bool isPlayingMusic();
	void stopMusic();

	void playEffect(std::string filename);
private:
	bool m_bPlayingMusic;
	int m_bgMusic;
};

static MusicPlayer* m_sharedInstance;

#endif //__MUSICPLAYER_H__