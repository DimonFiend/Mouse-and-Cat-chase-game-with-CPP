#include "Animator.h"

Animator::Animator(sf::Sprite& sprite)
	:m_sprite(sprite), m_frameTime(ANIMATION_TIME), m_currentFrame(0), m_elapsedTime(0.0f), m_currentState(Idle)
{
	m_animations.resize(ANIMATION_SETS);
	sf::IntRect rectSourceSprite = sprite.getTextureRect();
	m_animations[Idle].push_back(rectSourceSprite);
	nextSquare(rectSourceSprite);
	m_animations[AxisX].push_back(rectSourceSprite);
	nextSquare(rectSourceSprite);
	m_animations[AxisX].push_back(rectSourceSprite);
	nextSquare(rectSourceSprite);
	m_animations[AxisY].push_back(rectSourceSprite);
	nextSquare(rectSourceSprite);
	m_animations[AxisY].push_back(rectSourceSprite);
}

void Animator::nextSquare(sf::IntRect& rect)
{
	rect.left += rect.width+1;
}
void Animator::setAnimationState(Direction direction)
{
    switch (direction)
    {
    case Direction::Up:
    case Direction::Down:
        m_currentState = AxisY;
        break;
    case Direction::Left:
    case Direction::Right:
        m_currentState = AxisX;
        break;
    default:
        m_currentState = Idle;
        break;
    }
}

void Animator::update(sf::Time deltaTime, Direction direction)
{
    m_elapsedTime += deltaTime.asSeconds();

    // Set the animation state based on direction
    setAnimationState(direction);

    if (m_elapsedTime >= m_frameTime)
    {
        m_elapsedTime = 0.0f;
        m_currentFrame = (m_currentFrame + 1) % m_animations[m_currentState].size();
        m_sprite.setTextureRect(m_animations[m_currentState][m_currentFrame]);

        // Adjust the sprite's scale based on the direction
		abjustScale(direction);
    }
}

void Animator::abjustScale(Direction direction)
{
	switch (direction) {
	case Direction::Up:
		m_sprite.setScale(1.0f, 1.0f);
		break;
	case Direction::Down:
		m_sprite.setScale(1.0f, -1.0f);
		break;
	case Direction::Left:
		m_sprite.setScale(1.0f, 1.0f);
		break;
	case Direction::Right:
		m_sprite.setScale(-1.0f, 1.0f);
		break;
	default:
		m_sprite.setScale(1.0f, 1.0f);
		break;
	}
}