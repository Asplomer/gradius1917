#ifndef MENU_H
#define MENU_H
#include "FlowManager.h"
#include "Gameplay.h"
#include "Credits.h"
#include "raylib.h"
namespace flowspace {
	namespace menuspace {
		void initMenu();
		void updateMenu();
		void drawMenu();
		void exitGame();
		void startGame();
		void goToCredits();
	}
}
#endif