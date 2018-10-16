#include "FlowManager.h"
namespace flowspace {
	gamestate currentstate;
	bool gameSwitch;
	unsigned int screenheight = 600;
	unsigned int screenwidth = 800;
	Vector2 mousePosition;
	void initGame() {
		gameSwitch = true;
		InitWindow(screenwidth,screenheight,"Gradius 1917");
		menuspace::initMenu();
		currentstate = menustate;
		gameLoop();
	}
	void gameLoop() {
		while (gameSwitch){
			switch (currentstate){
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
		ClearBackground(BLACK);
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