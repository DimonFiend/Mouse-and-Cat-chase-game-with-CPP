#include "GameObject.h"

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::FloatRect GameObject::getBounds() const
{
	return m_sprite.getGlobalBounds();
}