#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class GameState {
public:
    GameState() = default;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleEvent(sf::RenderWindow& window) = 0;
    virtual ~GameState();
	virtual void stopMusic();
	virtual void setMusic(const std::string& musicPath, bool loop, float volume) ;

private:
	sf::Music m_music;

    virtual void setMusicVolume(float volume);
    virtual void setMusicLoop(bool loop);
};
