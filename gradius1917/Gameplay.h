#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "FlowManager.h"
#include "Menu.h"
#include "raylib.h"
namespace flowspace {
	namespace gameplayspace {
		void initGame();
		void updateGame();
		void drawGame();
		void goToMenu();
	}
}
#endif