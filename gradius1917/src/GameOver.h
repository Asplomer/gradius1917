#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "FlowManager.h"
#include "Gameplay.h"
#include "Menu.h"
#include "raylib.h"
namespace flowspace {
	namespace gameoverspace {
		void initGameOver();
		void updateGameOver();
		void drawGameOver();
		void restartGame();
		void goToMenu();
	}
}
#endif