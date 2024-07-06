///=======================================================================
/// \file	Resources.h
/// \brief	Header file for the Resources singleton class.
/// 
/// This class is a singleton class that manages all the resources of the game.
/// It loads the textures, sounds, fonts, and music of the game.
/// 
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

enum Objects {
	Cat, Mouse, Floor,
	Wall, Cheese,Door,
	Key, Present_Time,
	Present_Freeze,
	Present_CatDestr,
	Present_Life,
	FrozenEnemy,
	MaxObjects
};

enum Sounds{
	CatCollision, MouseEat, CatPunch,
	CatMeow, DoorLock, FreezeFx,
    KeyPickup, RemoveCat, TearPresent,
	MaxSounds
};

enum Music {
	M_MainMenu, M_GameLevel,
	M_GameFinish,M_GameOver,
	M_MaxMusic
};

enum Backgrounds {
	B_MainMenu,
	B_GameLevel,
	B_GameFinish,
	B_GameOver,
	B_HelpMenu,
	B_MaxBackgrounds
};

class Resources{
public:
	

	~Resources() = default;
	static Resources& instance();
	sf::Font& getFont() { return m_font;};
	sf::Texture& getButtonTexture() { return m_buttonTexture;};
	sf::Texture& getGameTexture() { return m_gameSprites; };
	void playSound(Sounds sound);
	const sf::IntRect getTextureRect(Objects object) const;
	const sf::Texture& getBackground(Backgrounds background) const;
	const sf::Texture& getUiBarTexture() const;
	const std::string getMusicPath(Music music) const;
private:
	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	void initTextures();
	void initSounds();
	void setSounds();
	void initBackgrounds();
	void initMusicPath();


	sf::Texture m_gameSprites;
	sf::Texture m_buttonTexture;
	sf::Texture m_backgrounds[B_MaxBackgrounds];
	sf::Texture m_UIbar;
	std::string m_musicPath[M_MaxMusic];
	sf::SoundBuffer m_soundBuffer[MaxSounds];
	sf::Sound m_sound[MaxSounds];
	sf::Font m_font;
	std::vector<sf::IntRect> m_data;
};