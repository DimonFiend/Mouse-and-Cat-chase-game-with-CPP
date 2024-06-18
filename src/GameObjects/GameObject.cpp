#include "GameObject.h"

GameObject::GameObject(const sf::Texture& texture, sf::Vector2f pos)
{
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(pos.x + textureSize.x/2, pos.y + textureSize.y/2);
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void GameObject::move(sf::Vector2f direction,float speed, sf::Time deltaTime)
{
	m_sprite.move(direction * speed * deltaTime.asSeconds());
}