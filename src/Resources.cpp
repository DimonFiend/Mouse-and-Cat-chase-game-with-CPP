#include "Resources.h"

Resources& Resources::Instance()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
{
	font.loadFromFile("ComicFont.ttf");
	buttonTexture.loadFromFile("Button.png");
}