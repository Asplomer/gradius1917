#include "GameOver.h"
namespace flowspace {
	namespace gameoverspace {
		void initGameOver(){
		
		}

		void updateGameOver(){
			if (IsKeyPressed(KEY_R)) {
				restartGame();
			}
			if (IsKeyPressed(KEY_M)) {
				goToMenu();
			}
		}

		void drawGameOver() {
			if (gameplayspace::won) {
				DrawText("YOU WON!", screenwidth / 2 - 300, screenheight / 2 - 30, 30, WHITE);
			}
			else {
				DrawText("YOU LOST!", screenwidth / 2 - 300, screenheight / 2 - 30, 30, WHITE);
			}
			DrawText("Press R to restart, M to go to the menu", screenwidth / 2 - 300, screenheight / 2 + 30, 25, GRAY);
		}

		void restartGame(){
			gameplayspace::initGame();
			currentstate = gameplaystate;
		}

		void goToMenu(){
			menuspace::initMenu();
			currentstate = menustate;
		}
	}
}