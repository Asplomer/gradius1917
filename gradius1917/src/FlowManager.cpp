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
		SetExitKey(0);
		InitAudioDevice();
		currentstate = menustate;
		gameLoop();
	}
	void gameLoop() {
		while (gameSwitch && !WindowShouldClose()){
			switch (currentstate){
			case menustate:
				menuspace::updateMenu();
				generalDraw();
				break;
			case gameplaystate:
				gameplayspace::updateGame();
				generalDraw();
				break;
			case creditsstate:
				creditsspace::updateCredits();
				generalDraw();
				break;
			case gameoverstate:
				gameoverspace::updateGameOver();
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
		case creditsstate:
			creditsspace::drawCredits();
			break;
		case gameoverstate:
			gameoverspace::drawGameOver();
			break;
		}

		EndDrawing();
	}
	void exitGame() {
		gameSwitch = !gameSwitch;
	}
}