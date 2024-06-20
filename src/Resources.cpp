#include "Resources.h"

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
{
	
}