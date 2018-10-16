#include "FlowManager.h"
namespace flowspace {
	gamestate currentstate;
	bool gameSwitch;
	void initGame() {
		InitWindow(800,600,"Gradius 1917");
		currentstate = menustate;
	}
	void gameLoop() {
		while (gameSwitch){
			switch (currentstate)
			{
			case menustate:
				menuspace::updateMenu();
				generalDraw();
				break;
			case gameplaystate:
				gameplayspace::updateGame();
				generalDraw();
				break;
			}
		}
	}
	void generalDraw() {
		BeginDrawing();
		switch (currentstate)
		{
		case menustate:
			menuspace::drawMenu();
			break;
		case gameplaystate:
			gameplayspace::drawGame();
			break;
		}
		EndDrawing();
	}
	void exitGame() {
		gameSwitch = !gameSwitch;
	}
}