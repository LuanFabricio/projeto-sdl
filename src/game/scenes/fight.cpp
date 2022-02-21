#include "../../../headers/game/scenes/fight.h"

Fight::Fight(int qEnemies){
	for(int i = 0 ; i < qEnemies ; i++){
		Enemy e("enemy", 100, 1, 3);
		enemies.push_back(e);
	}
}
