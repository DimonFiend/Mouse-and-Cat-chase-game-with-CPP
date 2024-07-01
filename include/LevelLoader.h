#pragma once
#include <fstream>
#include <sstream>
#include "PresentObject.h"
#include "EnemyObject.h"

class GameLevel;
class LevelLoader {

public:
	LevelLoader(GameLevel* manager, unsigned int level);
	void loadLevel();

	~LevelLoader();
private:
	std::ifstream m_file;
	std::stringstream m_fileName;
	GameLevel* m_manager;
	float m_height;
	float m_width;
	bool m_specialEnemy;
	unsigned int m_level;

	void setGameData();
	void setLine(std::string line);
	void push_object(char id, sf::Vector2f position);
	std::unique_ptr<PresentObject> generatePresent(sf::Vector2f position);
	std::unique_ptr<EnemyObject> generateEnemy(sf::Vector2f position);
};