#include "GameState.h"

GameState::~GameState()
{
	stopMusic();
}

void GameState::stopMusic()
{
	m_music.stop();
}

void GameState::setMusic(const std::string& musicPath, bool loop, float volume)
{
	m_music.openFromFile(musicPath);
	setMusicLoop(loop);
	setMusicVolume(volume);
	m_music.play();
}

void GameState::setMusicVolume(float volume)
{
	m_music.setVolume(volume);
}

void GameState::setMusicLoop(bool loop)
{
	m_music.setLoop(loop);
}