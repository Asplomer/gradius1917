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
		}
		void drawMenu() {
			DrawText("V para empezar, Q para salir",screenwidth/2 - 300, screenheight / 2- 30,40,WHITE);
		}
		void exitGame() {
			gameSwitch = false;
		}
		void startGame() {
			gameplayspace::initGame();
			currentstate = gameplaystate;
		}
	}
}