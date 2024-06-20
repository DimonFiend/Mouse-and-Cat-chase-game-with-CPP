#include "GameObject.h"

GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos)
{
	m_sprite.setTexture(texture);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(pos.x + textureSize.x/2, pos.y + textureSize.y/2);
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::Sprite& GameObject::getSprite()
{
	return m_sprite;
}

void GameObject::setTextureRect(sf::IntRect rect)
{
	m_sprite.setTextureRect(rect);
}