#include "Menu.h"
namespace flowspace {
	namespace menuspace {
		void initMenu() {
		}
		void updateMenu() {
			if (IsKeyPressed(KEY_V)) {
				startGame();
			}
			if (IsKeyPressed(KEY_Q)) {
				exitGame();
			}
			if (IsKeyPressed(KEY_C)) {
				goToCredits();
			}
		}
		void drawMenu() {
			DrawText("Press V to start, Q to exit",screenwidth/2 - 300, screenheight / 2- 30,40,WHITE);
			DrawText("Press C to view the Credits", screenwidth / 2 - 300, screenheight / 2, 40, WHITE);
			DrawText("Version 1.0", screenwidth / 2 - 40, screenheight - 20, 20, GRAY);
		}
		void exitGame() {
			gameSwitch = false;
		}
		void startGame() {
			gameplayspace::initGame();
			currentstate = gameplaystate;
		}
		void goToCredits() {
			creditsspace::initCredits();
			currentstate = creditsstate;
		}
	}
}