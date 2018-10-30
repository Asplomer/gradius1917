#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "FlowManager.h"
#include "Menu.h"
#include "GameOver.h"
#include "raylib.h"
namespace flowspace {
	namespace gameplayspace {
		void initGame();
		void updateGame();
		void drawGame();
		void goToMenu();
		void gameOver();

		struct player {
			Vector2 position;
			Vector2 speed;
			float acceleration;
			int colliderRadius;
			int hp;
			bool invulnerable;
			double lastInvulnerable;
		};

		struct bullet {
			bool active;
			Vector2 position;
			double birthDate;
			unsigned int colliderRadius;
		};

		struct enemy {
			bool active;
			Rectangle collisionRec;
			Vector2 position;
			Vector2 speed;
			float acceleration;
			int colliderRadius;
		};
		extern bool won;
	}
}
#endif