#include "GameObject.h"
#include "Resources.h"
GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition({ pos.x + 32 , pos.y + 32});
	
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}