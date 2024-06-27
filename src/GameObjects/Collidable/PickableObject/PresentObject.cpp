#include "PresentObject.h"
#include "Presents.h"

PresentObject::PresentObject(sf::Vector2f pos, std::unique_ptr<Presents> obj)
{
	m_present = std::move(obj);
	m_sprite.setTexture(Resources::instance().getGameTexture());
	m_sprite.setTextureRect(Resources::instance().getTextureRect(m_present->PresentId()));

	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();

	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}

bool PresentObject::checkCollision(CollidableObject& other)
{
	return m_sprite.getGlobalBounds().intersects(other.getBounds());
}

void PresentObject::handleCollision(CollidableObject& other)
{
	m_present->handleCollision(other);

	if (m_present->toDelete())
	{
		setToDelete();
	}
}