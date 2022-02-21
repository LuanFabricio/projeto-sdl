#ifndef SCENE_FIGHT
#define SCENE_FIGHT

#include "../../common.h"
#include "../entity.h"

class Fight{
	public:
		Fight(int enemies);

	private:
		std::vector<entity> enemies;
}

#endif
