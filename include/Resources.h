#pragma once
/*Resources class for textures, audio, fonts
  Work by singleton                       */

#include <SFML/Graphics.hpp>


class Resources{
public:
	~Resources() = default;
	static Resources& Instance();
	sf::Font& getFont() { return font;};
	sf::Texture& getButtonTexture() { return buttonTexture;};

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	sf::Texture buttonTexture;
	sf::Font font;
};