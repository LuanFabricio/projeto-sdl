#include "../headers/init.h"

void init(App &app){
	int renderFlags, windowFlags;
	renderFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Não consegui inicializar o vídeo\n";
		exit(1);
	}
	app.window = SDL_CreateWindow("Projeto",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	if(!app.window){
		std::cout << "Erro na hora de criar a janela\n";
		exit(1);
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	app.renderer = SDL_CreateRenderer(app.window, -1, renderFlags);
	if(!app.renderer){
		std::cout << "Erro na hora de criar o renderer\n";
		exit(1);
	}
	TTF_Init();
}

void init_cleanup(App &app){
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
}
