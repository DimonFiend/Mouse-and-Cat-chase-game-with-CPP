#pragma once
/*Resources class for textures, audio, fonts
  Work by singleton                       */

#include <SFML/Graphics.hpp>


class Resources{
public:
	~Resources() = default;
	static Resources& Instance();
	sf::Font& getFont() { return m_font;};
	sf::Texture& getButtonTexture() { return m_buttonTexture;};

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	sf::Texture m_cat;
	sf::Texture m_mouse;
	sf::Texture m_buttonTexture;
	sf::Font m_font;
};