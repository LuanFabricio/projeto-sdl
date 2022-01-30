#include "../headers/main.h"

App app;

void cleanup();

int main(){
	init(app);
	atexit(cleanup);
	Draw draw;
	Input input;
	Ui ui(app, draw);
	
	draw.createRect(640, 450, 1000, 250);
//	draw.createText("aaaa", 100, 100);
//	draw.createText("bbbb", 10, 10);

	while(1){
		input.listenInput(app, draw, ui);
		draw.preparateScene(app);
		draw.drawRects(app);
		draw.drawTexts(app);
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
