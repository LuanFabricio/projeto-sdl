#include "../../headers/game/ui.h"

const Color _selectColor = {0xD9, 0xDB, 0x53, 0xFF};
const Color _defaultColor = {0, 0, 0, 0xFF};

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
		Button b;
		b.textBox = draw.createRect(lastX, mainY, w[i], 40);
		b.text = draw.createText(actions[i], lastX, mainY, w[i]-15, 40, 48);
		b.color = _defaultColor;
		b.rectIndex = draw.getRectsSize()-1;
		b.textIndex = draw.getTextsSize()-1;
		buttons.push_back(b);
	}
	std::cout << rectsSize << std::endl;
	selectButton(0, draw, _selectColor);
	for(int i = 0 ; i < qButtons ; i++){
		Rect *r = buttons[i].textBox;
		std::cout << "[" << i << "]" << r->color.r << " " << r->color.g  << " " << r->color.b << " " << r->color.a << std::endl; 
	}
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
	Rect *r = buttons[indexUI].textBox;
	Color currentRectColor = r->color;
	if(currentRectColor.r != selectColor.r 
	&& currentRectColor.g != selectColor.g
	&& currentRectColor.b != selectColor.b
	&& currentRectColor.a != selectColor.a){
		buttons[indexUI].color = currentRectColor;
	}
	r->color = selectColor;
	std::cout << "[" << indexUI << "]" << r->color.r << " " << r->color.g  << " " << r->color.b << " " << r->color.a << " " << r->visible << " " << draw.getRectsSize() << std::endl; 
//	draw.setRectColor(indexDraw, selectColor);
	for(int i = 0 ; i < buttons.size() ; i++){
		Rect *r1 = buttons[i].textBox;
		std::cout << "[" << i << "]" << r1->color.r << " " << r1->color.g  << " " << r1->color.b << " " << r1->color.a << std::endl; 
	}
}

void Ui::getSelectedButton(Button &btn){
	btn = buttons[currentButton];
}

void Ui::startCombat(){
	for(int i = 0 ; i < buttons.size() ; i++){
		Rect *r = buttons[i].textBox;
		Text *t = buttons[i].text;
		r->visible = false;
		t->visible = false;
	}
}

void Ui::stopCombat(){
	for(int i = 0 ; i < buttons.size() ; i++){
		Rect *r = buttons[i].textBox;
		Text *t = buttons[i].text;
		r->visible = true;
		t->visible = true;
	}
}
