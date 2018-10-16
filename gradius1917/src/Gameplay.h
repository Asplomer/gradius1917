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

		struct player {
			Vector2 position;
			Vector2 speed;
			float acceleration;
		};

		struct enemy {
			bool active;
			Vector2 position;
			Vector2 speed;
			float acceleration;
		};
		extern bool won;
	}
}
#endif