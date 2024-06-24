#pragma once
/*Resources class for textures, audio, fonts
  Work by singleton                       */

#include <SFML/Graphics.hpp>
#include <vector>

enum Objects {
	Cat,
	Mouse,
	Floor,
	Wall,
	Cheese,
	Door,
	Key,
	Present_Time,
	Present_Freeze,
	Present_CatDestr,
	MaxObjects
};

class Resources{
public:
	

	~Resources() = default;
	static Resources& instance();
	sf::Font& getFont() { return m_font;};
	sf::Texture& getButtonTexture() { return m_buttonTexture;};
	sf::Texture& getGameTexture() { return m_gameSprites; };

	sf::IntRect getTextureRect(Objects object) { return m_data[object]; };

private:
	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	void initTextures();

	sf::Texture m_gameSprites;
	sf::Texture m_buttonTexture;

	sf::Font m_font;
	std::vector<sf::IntRect> m_data;
};