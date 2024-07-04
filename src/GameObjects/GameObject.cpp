#include "GameObject.h"
#include "Resources.h"
#include "Utilities.h"
GameObject::GameObject(sf::Vector2f pos, sf::IntRect obj)
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	m_sprite.setTextureRect(obj);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
	m_sprite.setPosition({ pos.x + POS_OFFSET, pos.y + POS_OFFSET });
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::FloatRect GameObject::getBounds() const
{
	return m_sprite.getGlobalBounds();
}