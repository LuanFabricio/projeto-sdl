#include "../../headers/game/buttonHandler.h"

void handleButton(Draw &draw, Button &btn){
	char* btnValue = btn.text->text; //draw.getTextContent(btn.textIndex);
	std::cout << btnValue << std::endl;
	if(!strcmp(btnValue, "atacar")){
		std::cout << "Atacando!\n";
	}
}
