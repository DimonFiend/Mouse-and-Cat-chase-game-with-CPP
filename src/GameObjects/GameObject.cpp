#include "GameObject.h"
#include "Resources.h"

GameObject::GameObject()
{
	m_sprite.setTexture(Resources::instance().getGameTexture());

}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::FloatRect GameObject::getBounds() const
{
	return m_sprite.getGlobalBounds();
}