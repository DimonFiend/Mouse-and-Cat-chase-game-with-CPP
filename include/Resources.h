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
	sf::Texture& getCatTexture() { return m_cat;};
	sf::Texture& getMouseTexture() { return m_mouse;};
	sf::Texture& getCheeseTexture() { return m_cheese;};
	sf::Texture& getFloorTexture() { return m_floor;};
	sf::Texture& getWallTexture() { return m_wall;};
	sf::Texture& getDoorTexture() { return m_door;};
	sf::Texture& getKeyTexture() { return m_key;};
	sf::Texture& getPresentTexture() { return m_present;};

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	sf::Texture m_cat;
	sf::Texture m_mouse;
	sf::Texture m_cheese;
	sf::Texture m_floor;
	sf::Texture m_wall;
	sf::Texture m_door;
	sf::Texture m_key;
	sf::Texture m_present;


	sf::Texture m_buttonTexture;
	sf::Font m_font;
};