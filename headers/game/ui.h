#ifndef UI
#define UI
#include "../common.h"
#include "../draw.h"

class Ui {
	public:
		Ui(App &app, Draw &draw);
		int currentButton = 0;
		std::vector<Button> buttons;
		void nextButton();
		void pastButton();
		void selectButton(int indexUI, Draw &draw, Color selectColor);
		Button getSelectedButton(Button &btn);
};

#endif
