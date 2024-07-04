#include "SmartCatEnemy.h"
#include "Resources.h"
#include "Configs.h"
#include "GameLevel.h"
#include <unordered_set>
#include <unordered_map>
#include <queue>


SmartCatEnemy::SmartCatEnemy(sf::Vector2f pos)
	:EnemyObject(SMART_CAT_SPEED, pos, Resources::instance().getTextureRect(Objects::Cat))
{
	m_sprite.setColor(sf::Color::Red);
}

void SmartCatEnemy::move(sf::Time deltaTime, GameLevel* manager)
{
	EnemyObject::catSpeak();
	if (EnemyObject::checkFreezeStatus())
	{
		return;
	}

	this->getDirection(manager);
	auto movement = MovingObject::enumToVector() * EnemyObject::getSpeed() * deltaTime.asSeconds();
	MovingObject::setLastPos(m_sprite.getPosition());
	m_sprite.move(movement);
	MovingObject::Animate(deltaTime, m_direction);
}

void SmartCatEnemy::handleCollision(WallObject& other)
{
	(void)other;
	m_sprite.setPosition(MovingObject::getLastPos());
}

void SmartCatEnemy::getDirection(GameLevel* manager)
{
	auto relativePos = EnemyObject::calcRelativePos(m_sprite.getPosition());

	if (std::abs(relativePos.x - 32) < 4 && std::abs(relativePos.y - 32) < 4)
	{
		this->directionBfs(manager);
	}
}

// BFS algorithm to find the shortest path to the player
//the function inserts into the queue the next possible path
//the 1D data structures uses linear function of the map size
//to store the visited vectors and the predecessors
void SmartCatEnemy::directionBfs(GameLevel* manager)
{
	auto mapSize = MovingObject::toGridIndex(manager->getMapSize());

	// Initialize the visited vectors and predecessors
	std::unique_ptr<bool[]> visitedVectors = std::make_unique<bool[]>(mapSize.x * mapSize.y);
	Predecessors pred = initializePred(mapSize);
    std::queue<sf::Vector2i> queue;

	auto posIndex = MovingObject::toGridIndex(m_sprite.getPosition());
	pred[posIndex.x + posIndex.y] = posIndex;
    queue.push(posIndex);

    while (!queue.empty())
    {
		MovablePath path = manager->getPath(queue.front());
        sf::Vector2i curPos = queue.front();
        queue.pop();

		for (auto& neighborPos : path)
		{
			auto index = neighborPos.x + neighborPos.y * mapSize.x;
			if (!visitedVectors[index])
			{
				queue.push(neighborPos);
				pred[index] = sf::Vector2i{curPos.x, curPos.y};
			}
		}

		visitedVectors[curPos.x + curPos.y * mapSize.x] = true;
    }

	nextPath(pred, manager, mapSize.x);
}

// Initialize the predecessors vector with -1 so all grid indexes can be checked
Predecessors SmartCatEnemy::initializePred(const sf::Vector2i& mapSize) const
{
	Predecessors pred = std::make_unique<sf::Vector2i[]>(mapSize.x * mapSize.y);
	for (int i = 0; i < mapSize.x * mapSize.y; i++)
	{
		pred[i] = sf::Vector2i{ -1, -1 };
	}
	return pred;
}

// Find the next path to the player
// The function uses the predecessors vector to find the next path
void SmartCatEnemy::nextPath(const Predecessors& pred, GameLevel* manager, int mapWidth)
{
    auto playerPos = MovingObject::toGridIndex(manager->getPlayerPosition());
    sf::Vector2i currentPos = MovingObject::toGridIndex(m_sprite.getPosition());

    std::vector<sf::Vector2i> path;
	auto pos = playerPos;

	if (pred[pos.x + pos.y * mapWidth] == sf::Vector2i{ -1, -1 })
	{
		m_direction = Idle;
		return;
	};

    while (pos != currentPos)
    {
        path.push_back(pos);
        pos = pred[pos.x + pos.y * mapWidth];
    }

    path.push_back(currentPos);

    if (path.size() > 1)
    {
		pathToEnum(currentPos, path[path.size() - 2]);
    }

}

// Convert the path to the next grid to enum
void SmartCatEnemy::pathToEnum(const sf::Vector2i& curr, const sf::Vector2i& next)
{
	auto nextPath = sf::Vector2i{ next.x - curr.x, next.y - curr.y };

	if (nextPath.x == 0 && nextPath.y == 1) { m_direction = Down; }
	else if (nextPath.x == 0 && nextPath.y == -1) { m_direction = Up; }
	else if (nextPath.x == 1 && nextPath.y == 0) { m_direction = Right; }
	else if (nextPath.x == -1 && nextPath.y == 0) { m_direction = Left; }
}

//=============================================================================
/*-----------------------------Collision handlers-----------------------------*/
void SmartCatEnemy::handleCollision(CatEnemy& other)
{
	other.handleCollision(*this);
}

void SmartCatEnemy::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void SmartCatEnemy::handleCollision(MousePlayer& other)
{
	if (!isFrozen())
	{
		other.handleCollision(*this);
		soundOnPlayerHit();
	}
}
