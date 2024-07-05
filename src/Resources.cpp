#include "Resources.h"
#include "Configs.h"
Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
{
	m_data.resize(MaxObjects);
	m_font.loadFromFile("ComicFont.ttf");
	m_gameSprites.loadFromFile("GameSprites.png");
	m_buttonTexture.loadFromFile("Button.png");
	m_UIbar.loadFromFile("UIBar.png");
	initTextures();
	initSounds();
	initMusic();
	initBackgrounds();
}

void Resources::initTextures()
{
	auto bigSize = sf::Vector2i(64, 64);
	auto smallSize = sf::Vector2i(48, 48);

	m_data[Cat] = sf::IntRect({ 0,0 }, smallSize);
	m_data[Mouse] = sf::IntRect({ 0, 49 }, smallSize);
	m_data[Floor] = sf::IntRect({ 0, 196 }, bigSize);
	m_data[Wall] = sf::IntRect({ 65, 196 }, bigSize);
	m_data[Cheese] = sf::IntRect({ 49, 98 }, smallSize);
	m_data[Door] = sf::IntRect({ 130, 196 }, bigSize);
	m_data[Key] = sf::IntRect({0, 98}, smallSize);
	m_data[Present_Time] = sf::IntRect({ 98, 147 }, smallSize);
	m_data[Present_Freeze] = sf::IntRect({ 49, 147 }, smallSize);
	m_data[Present_CatDestr] = sf::IntRect({ 0, 147 }, smallSize);
	m_data[Present_Life] = sf::IntRect({ 147, 147 }, smallSize);
	m_data[FrozenEnemy] = sf::IntRect({ 245, 0 }, smallSize);
}

void Resources::initBackgrounds()
{
	m_backgrounds[B_MainMenu].loadFromFile("Mouse_Run_Background.jpg");
	m_backgrounds[B_GameLevel].loadFromFile("LevelBackground.png");
}

void Resources::initSounds()
{
	m_soundBuffer[CatCollision].loadFromFile("CatHiss.wav");
	m_soundBuffer[MouseEat].loadFromFile("MouseEat.wav");
	m_soundBuffer[CatPunch].loadFromFile("CatPunch.wav");
	m_soundBuffer[CatMeow].loadFromFile("CatMeow.wav");
	m_soundBuffer[DoorLock].loadFromFile("DoorLock.wav");
	m_soundBuffer[FreezeFx].loadFromFile("FreezeFX.wav");
	m_soundBuffer[KeyPickup].loadFromFile("KeyPick.wav");
	m_soundBuffer[RemoveCat].loadFromFile("RemoveCat.wav");
	m_soundBuffer[TearPresent].loadFromFile("TearPresent.wav");
	loadSounds();
}

void Resources::initMusic()
{
	m_music[M_MainMenu].openFromFile("MainMenu.wav");
	m_music[M_GameLevel].openFromFile("GameLevel.wav");
	m_music[M_GameFinish].openFromFile("GameFinish.wav");
	m_music[M_GameOver].openFromFile("GameOver.wav");

	m_music[M_GameOver].setLoop(false);
	m_music[M_GameFinish].setLoop(false);
	m_music[M_MainMenu].setLoop(true);
	m_music[M_GameLevel].setLoop(true);
}

void Resources::loadSounds()
{
	for (int i = 0; i < MaxSounds; i++)
	{
		m_sound[i].setBuffer(m_soundBuffer[i]);
	}
}

void Resources::playSound(Sounds sound)
{
	m_sound[sound].setVolume(SOUND_VOLUME);
	m_sound[sound].play();
}

void Resources::playMusic(Music music)
{
	m_music[music].setVolume(MUSIC_VOLUME);
	m_music[music].play();
}

void Resources::stopMusic(Music music)
{
	m_music[music].stop();
}

const sf::IntRect Resources::getTextureRect(Objects object) const
{
	return m_data[object];
}

const sf::Texture& Resources::getBackground(Backgrounds background) const
{
	return m_backgrounds[background];
}

const sf::Texture& Resources::getUiBarTexture() const
{
	return m_UIbar;
}