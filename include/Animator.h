///=======================================================================
/// \file	Animator.h
/// \brief	Header file for the Animator class.
/// the Animator class is responsible for the animation of the characters.

#pragma once
#include "SFML/Graphics.hpp"
#include "Utilities.h"

class Animator {
public:

	Animator() = delete;
	Animator(sf::Sprite& sprite);
	~Animator() = default;
	void update(sf::Time deltaTime, Direction direction);

private:
	enum AnimationType { Idle, AxisX, AxisY };
	sf::Sprite& m_sprite;
	float m_frameTime;
	float m_elapsedTime;
	int m_currentFrame;
	AnimationType m_currentState;
	std::vector<std::vector<sf::IntRect>> m_animations;
	void nextSquare(sf::IntRect& rect);
	void setAnimationState(Direction direction);
	void abjustScale(Direction direction);
};