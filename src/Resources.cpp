#include "Resources.h"

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
{
	m_font.loadFromFile("ComicFont.ttf");
	m_buttonTexture.loadFromFile("Button.png");
	m_cat.loadFromFile("cat_sheet.png");
	m_mouse.loadFromFile("mouse_sheet.png");
	m_cheese.loadFromFile("Cheese.png");
	m_floor.loadFromFile("Floor.png");
	m_wall.loadFromFile("Wall.png");
	m_door.loadFromFile("Door.png");
	m_key.loadFromFile("Key.png");
	m_present.loadFromFile("Present.png");
}