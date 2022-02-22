#include "../../../headers/game/scenes/fight.h"

Fight::Fight(int qEnemies){
	srand(time(NULL));
	const int max_width = 640;
	const int min_width = 640 - 500;
	const int max_height = 450 - 125;
	const int min_height = 125;
	for(int i = 0 ; i < qEnemies ; i++){
		Entity *e = new Entity("enemy", 100, 1, 3);
		e->x = rand()%max_width + min_width; 
		e->y = rand()%max_height + min_height; 
		enemies.push_back(e);
	}
}

void Fight::loadTextures(App app, char* path, Draw &draw){
	SDL_Texture *texture = loadTexture(app, path);
	for(int i = 0 ; i < enemies.size() ; i++){
		Entity *e = enemies[i];
		std::cout << "X e Y\n";
		std::cout << e->x << " " << e->y << std::endl;
		e[i].text = draw.createTexture(texture, e->x, e->y, 100, 100);
	}
}
