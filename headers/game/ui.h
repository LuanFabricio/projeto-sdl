#ifndef UI
#define UI
#include "../common.h"
#include "../draw.h"

class Ui {
	public:
		Ui(App &app, Draw &draw);
		/*
		 * status | gamemode
		 *  0	  | combatBox
		 *  1	  | combat
		 * */
		int status = 0;
		int currentButton = 0;
		std::vector<Button> buttons;
		void nextButton();
		void pastButton();
		void selectButton(int indexUI, Draw &draw, Color selectColor);
		void getSelectedButton(Button &btn);
		void startCombat();
		void stopCombat();
};

#endif
