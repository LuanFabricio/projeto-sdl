#ifndef STRUCTS
#define STRUCTS

typedef struct Color {
	int r, g, b, a;
} Color;

typedef struct App {
	SDL_Window *window;
	SDL_Renderer *renderer;
} App;

typedef struct Texture {
	SDL_Texture *texture;
	int x, y, w, h;
	bool visible;
} Texture;

#endif
