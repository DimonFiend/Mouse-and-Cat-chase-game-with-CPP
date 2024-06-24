#include "FloorObject.h"
#include "Resources.h"

FloorObject::FloorObject(sf::Vector2f pos)
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::Floor));
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	auto posOrigin = sf::Vector2f(pos.x + textureSize.x / 2.f, pos.y + textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}
