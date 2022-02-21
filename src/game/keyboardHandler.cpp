#include "../../headers/game/keyboardHandler.h"

const Color selectColor = {0xD9, 0xDB, 0x53, 0xFF};
const Color defaultColor = {0, 0, 0, 0xFF};

static bool show_ui = true;

void handleKeyboard(Ui &ui, Draw &draw, SDL_Keycode key){
	switch(key){
		case SDLK_LEFT:
			ui.selectButton(ui.currentButton, draw, defaultColor);
			ui.pastButton();
			std::cout << ui.currentButton << "\n";
			ui.selectButton(ui.currentButton, draw, selectColor);
//			std::cout << "[UI]\n";
//			std::cout << "[" << ui.currentButton << "]" << ui.buttons[ui.currentButton].textBox->color.r << " " << ui.buttons[ui.currentButton].textBox->color.g << " " << ui.buttons[ui.currentButton].textBox->color.b << " "<< ui.buttons[ui.currentButton].textBox->color.a << std::endl;
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
			if(show_ui){
				ui.startCombat();
			}
			else{
				ui.stopCombat();
			}
			show_ui = !show_ui;
			handleButton(draw, btn);
//			std::cout << "Informações: (" << btn.rectIndex << " " << btn.textIndex << ")" << std::endl;
			break;
		default:
			break;
	}
}
