#include "../headers/main.h"

void cleanup();

int main(){
	init(app);
	atexit(cleanup);
	Draw draw;
	Input input;
	Ui ui(app, draw);
	std::vector<Entity> entities;
	Entity player("player", 10, 2, 5);
	Entity enemy("enemy", 8, 1, 2);
	entities.push_back(player);

	SDL_Texture *t = loadTexture(app, "assets/pc.png");
	if(!t){
		std::cout << "Error!\n";
		std::cout << SDL_GetError();
	}
	const int ENEMY_X = SCREEN_WIDTH/2;
        const int ENEMY_Y = SCREEN_HEIGHT/2;
	draw.createTexture(t, ENEMY_X, ENEMY_Y, 100, 100);
	enemy.x = ENEMY_X;
	enemy.y = ENEMY_Y;
	enemy.index = draw.getTextsSize()-1;

	draw.createRect(640, 450, 1000, 250);
//	draw.createText("aaaa", 100, 100);
//	draw.createText("bbbb", 10, 10);

	while(1){
		input.listenInput(app, draw, ui);
		draw.preparateScene(app);
		draw.drawRects(app);
		draw.drawTexts(app);
		draw.drawTextures(app);
		draw.presentScene(app);
	}
	std::cout << "Done!\n";

	TTF_Quit();
	SDL_Quit();
	
	return 0;
}

void cleanup(){
	init_cleanup(app);
}
