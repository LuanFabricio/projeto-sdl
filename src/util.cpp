#include "../headers/util.h"

SDL_Texture* loadTexture(App app, char* path){
	SDL_Texture *texture = IMG_LoadTexture(app.renderer, path);

	return texture;
}

void blit(App app, Texture texture){
	int x, y, w, h;
	w = texture.w;
	h = texture.h;
	x = texture.x-w/2;
	y = texture.y-h/2;
	SDL_Rect rect = { x, y, w, h };
	double angle = 0;
	SDL_RenderCopyEx(app.renderer, texture.texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}
