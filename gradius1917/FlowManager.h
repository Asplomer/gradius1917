#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H
#include "raylib.h"
#include "Gameplay.h"
#include "Menu.h"
#include <iostream>
namespace flowspace {
	enum gamestate{
		menustate, gameplaystate, gameoverstate, credtisstate
	};
	extern bool gameSwitch;
	extern gamestate currentstate;
	void initGame();
	void gameLoop();
	void generalDraw();
	void exitGame();
}
#endif