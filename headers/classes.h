#ifndef CLASSES
#define CLASSES
#include <SDL2/SDL.h>
#include "structs.h"

class Rect{
	public:
		SDL_Rect rect;
		Color color;
		bool visible = true;
};

class Button{
	public:
		int rectIndex, textIndex;
		Color color;
};

class Text {
	public:
		int index, x, y, sizeX, sizeY, offX, offY, fontSize;
		SDL_Color color;
		char* text;
		bool visible = true;
};
#endif
