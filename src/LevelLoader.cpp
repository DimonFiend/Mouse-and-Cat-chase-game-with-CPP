#include "LevelLoader.h"
#include <fstream>
#include <string>
#include "GameLevel.h"

LevelLoader::LevelLoader(GameLevel* manager, unsigned int level)
{
	loadLevel();
}


LevelLoader::~LevelLoader()
{
	if (m_file.is_open())
		m_file.close();
}