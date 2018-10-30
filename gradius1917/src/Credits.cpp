#include "Credits.h"
namespace flowspace {
	namespace creditsspace {
		void initCredits(){
		
		}

		void updateCredits(){
			if (IsKeyPressed(KEY_M)) {
				goToMenu();
			}
		}

		void drawCredits(){
			DrawText("Game made by Julian Serulnikov with Raylib", screenwidth / 2 - 300, screenheight / 2 - 30, 30, WHITE);
			DrawText("Music made with Bosca Ceoil, sprites made with Piskel", screenwidth / 2 - 300, screenheight / 2 +30, 25, WHITE);
			DrawText("Press M to return to the Menu", screenwidth / 2 - 300, screenheight / 2 +60, 20, GRAY);
			DrawText("Version 1.0", screenwidth / 2 - 40, screenheight -20, 20, GRAY);
		}

		void goToMenu(){
			menuspace::initMenu();
			currentstate = menustate;
		}
	}
}