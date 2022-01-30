#ifndef DRAW
#define DRAW
#include "common.h"

class Draw{
	public:
		void preparateScene(App &app);
		void presentScene(App &app);
		void createRect(int x, int y, int sizeX = 10, int sizeY = 10);
		void createText(char *text, int x, int y, int sizeX = 10, int sizeY = 10, int fontSize = 16);
		void drawRects(App &app);
		void drawTexts(App &app);
		void setRectColor(int index, Color color);
		Color getRectColor(int index);
		int getRectsSize();
		int getTextsSize();
	private:
		std::vector<Rect> rects;
		std::vector<Text> texts;
};
#endif
