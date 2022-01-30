#include "../headers/input.h"

void Input::listenInput(App &app, Draw &draw, Ui &ui){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYDOWN:
				handleKeyboard(ui, draw, event.key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				std::cout << "Button down\n";
				int x, y;
				x = event.button.x;
				y = event.button.y;
				draw.createRect(x, y);
				break;
			case SDL_QUIT:
				SDL_Quit();
				TTF_Quit();
				exit(0);
				break;
			default:
				break;
		}
	}
}
