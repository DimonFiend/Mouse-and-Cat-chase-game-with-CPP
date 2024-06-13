#include "GameObject.h"

GameObject::GameObject(const sf::Texture* const texture)
{
	m_sprite.setTexture(*texture);
}