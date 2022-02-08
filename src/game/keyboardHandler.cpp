#include "../../headers/game/keyboardHandler.h"

const Color selectColor = {0xd9, 0xdb, 0x53, 0xff};
const Color defaultColor = {0, 0, 0, 0xff};

void handleKeyboard(Ui &ui, Draw &draw, SDL_Keycode key){
	switch(key){
		case SDLK_LEFT:
			ui.selectButton(ui.currentButton, draw, defaultColor);
			ui.pastButton();
			std::cout << ui.currentButton << "\n";
			ui.selectButton(ui.currentButton, draw, selectColor);
			break;
		case SDLK_RIGHT:
			ui.selectButton(ui.currentButton, draw, defaultColor);
			ui.nextButton();
			std::cout << ui.currentButton << "\n";
			ui.selectButton(ui.currentButton, draw, selectColor);
			break;
		case SDLK_SPACE:
		case SDLK_RETURN:
			Button btn;
			ui.getSelectedButton(btn);
			handleButton(draw, btn);
			std::cout << "Informações: (" << btn.rectIndex << " " << btn.textIndex << ")" << std::endl;
			break;
		default:
			break;
	}
}
