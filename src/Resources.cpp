#include "Resources.h"

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
	initTextures();
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
}