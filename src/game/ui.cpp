#include "../../headers/game/ui.h"

const Color selectColor = {0xd9, 0xdb, 0x53, 0xff};
const Color defaultColor = {0, 0, 0, 0xff};

Ui::Ui(App &app, Draw &draw){
	int rectsSize = draw.getRectsSize();
	int textsSize = draw.getTextsSize();
	int qButtons = 4;
	const int mainY = 500;
	char* actions[4] = {
		"atacar",
		"conversar",
		"itens",
		"fugir"
	};
	int w[] = { 100, 150, 90, 90 };
	int gap[] = { 0, 150, 150, 115 };
	int lastX = 250;
	for(int i = 0; i < qButtons ; i++){
		lastX += gap[i];
		std::cout << lastX << " " << w[i] << std::endl;
		draw.createRect(lastX, mainY, w[i], 40);
		draw.createText(actions[i], lastX, mainY, w[i]-15, 40, 48);
		Button b;
		b.rectIndex = rectsSize+i;
		b.textIndex = textsSize+i;
		b.color = defaultColor;
		buttons.push_back(b);
	}
	std::cout << rectsSize << std::endl;
	selectButton(0, draw, selectColor);
}

void Ui::nextButton(){
	currentButton = (currentButton+1)%buttons.size();
}

void Ui::pastButton(){
	currentButton--;
	if(currentButton < 0){
		currentButton = buttons.size() - 1;
	}
}

void Ui::selectButton(int indexUI, Draw &draw, Color selectColor){
	int indexDraw = buttons[indexUI].rectIndex;
	Color currentRectColor = draw.getRectColor(indexDraw);
	if(currentRectColor.r != selectColor.r 
	&& currentRectColor.g != selectColor.g
	&& currentRectColor.b != selectColor.b
	&& currentRectColor.a != selectColor.a){
		buttons[indexUI].color = currentRectColor;
	}
	draw.setRectColor(indexDraw, selectColor);
}

void Ui::getSelectedButton(Button &btn){
	btn = buttons[currentButton];
}
