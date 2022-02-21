#ifndef DRAW
#define DRAW
#include "common.h"
#include "util.h"

class Draw{
	public:
		void preparateScene(App &app);
		void presentScene(App &app);
		// Rect stuff
		Rect* createRect(int x, int y, int sizeX = 10, int sizeY = 10, bool visible = true);
		void drawRects(App &app);
		int getRectsSize();
		void setRectColor(int index, Color color);
		Color getRectColor(int index);
		// Text stuff
		void drawTexts(App &app);
		Text* createText(char *text, int x, int y, int sizeX = 10, int sizeY = 10, int fontSize = 16);
		int getTextsSize();
		char* getTextContent(int index);
		// Texture stuff
		Texture* createTexture(SDL_Texture *texture, int x, int y, int width, int height);
		void drawTextures(App &app);
		void updateTextureCoords(int index, int x, int y);
		void updateTextureVisibility(int index, bool newVisible);
	private:
		std::vector<Rect*> rects;
		std::vector<Text*> texts;
		std::vector<Texture> textures;
};
#endif
