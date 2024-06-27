#include "LevelLoader.h"
#include <string>
#include <iomanip>
#include "GameLevel.h"

#include "ObjectsInclude.h"
#include "MousePlayer.h"
#include "CatEnemy.h"
#include "SmartCatEnemy.h"

LevelLoader::LevelLoader(GameLevel* manager, unsigned int level)
	: m_manager(manager), m_height(0), m_width(0), m_specialEnemy(false), m_level(level)
{}


LevelLoader::~LevelLoader()
{
	if (m_file.is_open())
		m_file.close();
}

void LevelLoader::loadLevel()
{
	m_fileName << "Level_" << std::setw(3) << std::setfill('0') << m_level << ".txt";
	m_file.open(m_fileName.str());
	if (!m_file.is_open())
	{
		//manager->endOfLevels();
	}
	else
	{
		setGameData();
	}
}

void LevelLoader::setGameData()
{
	std::string line;
	while (std::getline(m_file, line))
	{
		setLine(line);
		if (m_width < line.size())
		{
			m_width = static_cast<float>(line.size());
		}
		m_height++;
	}

	m_manager->setMapSize(sf::Vector2f(m_width*64, m_height*64));
}

void LevelLoader::setLine(std::string line)
{
	size_t lineSize = line.size();

	for (size_t i = 0; i < lineSize; i++)
	{
		sf::Vector2f position(static_cast<int>(i) * 64, m_height * 64);
		push_object(line[i], position);
	}
}

void LevelLoader::push_object(char id, sf::Vector2f position)
{
	switch (id)
	{
	case 'F':
		m_manager->setCollidable(std::make_unique<KeyObject>(position));
		m_manager->setStatic(std::make_unique<FloorObject>(position));
		break;
	case '$':
		//m_manager->setCollidable(generatePresent(position));
		m_manager->setStatic(std::make_unique<FloorObject>(position));
		break;
	case 'D':
		m_manager->setCollidable(std::make_unique<DoorObject>(position));
		m_manager->setStatic(std::make_unique<FloorObject>(position));
		break;
	case '*':
		m_manager->setCollidable(std::make_unique<CheeseObject>(position));
		m_manager->setStatic(std::make_unique<FloorObject>(position));
		break;
	case '#':
		m_manager->setCollidable(std::make_unique<WallObject>(position));
		break;
	case ' ':
		m_manager->setStatic(std::make_unique<FloorObject>(position));
		break;
	case '%':
		m_manager->setPlayer(std::make_unique<MousePlayer>(position));
		m_manager->setStatic(std::make_unique<FloorObject>(position));
		break;
	case '^':
		m_manager->setEnemy(generateEnemy(position));
		m_manager->setStatic(std::make_unique<FloorObject>(position));
		break;
	default:
		break;
	}
}
/*
std::unique_ptr<PresentObject> LevelLoader::generatePresent(sf::Vector2f position)
{
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		return std::make_unique<PresentObject>(position, std::make_unique<DestroyPresent>());
	case 1:
		return std::make_unique<PresentObject>(position, std::make_unique<TimePresent>());
	case 2:
		return std::make_unique<PresentObject>(position, std::make_unique<FreezePresent>());
	default:
		return nullptr;
	
}
*/
std::unique_ptr<EnemyObject> LevelLoader::generateEnemy(sf::Vector2f position)
{
	if (!m_specialEnemy && m_manager->getEnemyCount() > 1)
	{
		m_specialEnemy = true;
		return std::make_unique<SmartCatEnemy>(position);
	}
	else
	{
		return std::make_unique<CatEnemy>(position);
	}
}
