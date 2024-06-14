#include "GameObject.h"

GameObject::GameObject(const sf::Texture* const texture, sf::Vector2f pos)
{
	m_sprite.setTexture(*texture);
}