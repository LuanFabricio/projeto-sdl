#ifndef SCENE_FIGHT
#define SCENE_FIGHT

#include "../../common.h"
#include "../entity.h"

class Fight{
	public:
		Fight(int qEnemies);
		void loadTextures(App app, char* path, Draw &draw);
	private:
		std::vector<Entity*> enemies;
};

#endif
