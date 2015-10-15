
#include "MusicPlayer.h"
using namespace cocos2d;
using namespace experimental;

MusicPlayer::MusicPlayer() {
	m_bPlayingMusic = false;
	m_bgMusic = -1;
}

MusicPlayer::~MusicPlayer() {

}

MusicPlayer* MusicPlayer::getInstance() {
	if (!m_sharedInstance) {
		m_sharedInstance = new MusicPlayer();
	}
	return m_sharedInstance;
}

void MusicPlayer::playMusic(std::string filename) {
	if (m_bgMusic == -1) {
		m_bgMusic = AudioEngine::play2d(filename, true);
	}
}

bool MusicPlayer::isPlayingMusic() {
	return m_bgMusic != -1;
}

void MusicPlayer::stopMusic() {
	if (m_bgMusic != -1) {
		AudioEngine::stop(m_bgMusic);
		m_bgMusic = -1;
	}
}

void MusicPlayer::playEffect(std::string filename) {
	AudioEngine::play2d(filename);
}