#pragma once
/*Resources class for textures, audio, fonts
  Work by singleton                       */

#include <SFML/Graphics.hpp>


class Resources{
public:
	~Resources() = default;
	static Resources& instance();
	sf::Font& getFont() { return m_font;};
	sf::Texture& getButtonTexture() { return m_buttonTexture;};
	sf::Texture& getGameSprites() { return m_gameSprites; };

	sf::IntRect getCatRect() { return sf::IntRect(0, 0, 48, 48); };
	sf::IntRect getMouseRect() { return sf::IntRect(49, 49, 48, 48); };

private:
	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	sf::Texture m_gameSprites;
	sf::Texture m_buttonTexture;
	sf::Font m_font;
};