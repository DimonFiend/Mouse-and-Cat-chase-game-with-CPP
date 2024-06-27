#include "CatEnemy.h"
#include "Resources.h"

CatEnemy::CatEnemy(sf::Vector2f pos)
	:EnemyObject(70), m_direction(static_cast<Direction>(rand() %  4))
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	auto rect = Resources::instance().getTextureRect(Objects::Cat);
	m_sprite.setTextureRect(rect);
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
	MovingObject::setSpawn(posOrigin);
	MovingObject::setLastPos(posOrigin);
}

void CatEnemy::move(sf::Time deltaTime)
{
	sf::Vector2f movement = getDirection();
	MovingObject::setLastPos(m_sprite.getPosition());
	m_sprite.move(movement * EnemyObject::getSpeed() * deltaTime.asSeconds());
}

void CatEnemy::handleCollision(WallObject& other)
{
    handleObstruct();
}

void CatEnemy::handleCollision(DoorObject& other)
{
    handleObstruct();
}

void CatEnemy::handleObstruct()
{
    m_sprite.setPosition(MovingObject::getLastPos());
    m_direction = static_cast<Direction>(rand() % 4);
}

sf::Vector2f CatEnemy::getDirection()
{
	//will change that to a better way to change direction
    int timer_stop = rand() % 7 + 7;

    if (m_time.getElapsedTime().asSeconds() >= timer_stop)
    {
        m_direction = static_cast<Direction>((static_cast<int>(m_direction) + 1) % 4);
        m_time.restart();
    }

    sf::Vector2f movement(0, 0);
    switch(m_direction)
    {
        case UP:
            movement.y = -1;
            break;
        case Down:
            movement.y = 1;
            break;
        case Left:
            movement.x = -1;
            break;
        case Right:
            movement.x = 1;
            break;
    }
    return movement;
}