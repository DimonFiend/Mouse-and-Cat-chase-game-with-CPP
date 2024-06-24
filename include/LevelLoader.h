#pragma once

class GameLevel;
class LevelLoader {

public:
	LevelLoader(GameLevel* manager, unsigned int level);
	~LevelLoader();
private:
	std::ifstream m_file;

};