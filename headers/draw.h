#ifndef DRAW
#define DRAW
#include "common.h"
#include "util.h"

class Draw{
	public:
		void preparateScene(App &app);
		void presentScene(App &app);
		void createRect(int x, int y, int sizeX = 10, int sizeY = 10);
		void createText(char *text, int x, int y, int sizeX = 10, int sizeY = 10, int fontSize = 16);
		void createTexture(SDL_Texture *texture, int x, int y, int width, int height);
		void drawRects(App &app);
		void drawTexts(App &app);
		void drawTextures(App &app);
		void setRectColor(int index, Color color);
		Color getRectColor(int index);
		int getRectsSize();
		int getTextsSize();
		void updateTextureCoords(int index, int x, int y);
		void updateTextureVisibility(int index, bool newVisible);
	private:
		std::vector<Rect> rects;
		std::vector<Text> texts;
		std::vector<Texture> textures;
};
#endif
