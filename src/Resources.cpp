#include "Resources.h"

Resources& Resources::Instance()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
{
	m_font.loadFromFile("ComicFont.ttf");
	m_buttonTexture.loadFromFile("Button.png");
}