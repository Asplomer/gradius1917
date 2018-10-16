#include "Gameplay.h"
namespace flowspace {
	namespace gameplayspace {
		player p1;
		enemy e1;
		Vector2 defaultPosition;
		void initGame() {
			defaultPosition.x = 30;
			defaultPosition.y = screenheight / 2;
			p1.position = defaultPosition;
			p1.colliderRadius = 7.0;
			e1.position.x = screenwidth - 30;
			e1.position.y = screenheight / 2;
			e1.active = true;
			e1.colliderRadius = 7.0;
			e1.acceleration = 400;
			p1.acceleration = 200;
		}
		void updateGame() {
			if (IsKeyDown(KEY_S)){
				p1.position.y += p1.acceleration * GetFrameTime();
			}
			if (IsKeyDown(KEY_W)) {
				p1.position.y -= p1.acceleration * GetFrameTime();
			}
			if (IsKeyPressed(KEY_Q)) {
				goToMenu();
			}
			e1.position.x -= e1.acceleration * GetFrameTime();
			if (e1.position.x <= 0) {
				e1.position.x = screenwidth - 30;
				e1.position.y = GetRandomValue(10,screenheight-10);
			}

			//---------------collisions-----------------
			if (abs(p1.position.x - e1.position.x) < e1.colliderRadius && abs(p1.position.y - e1.position.y) < e1.colliderRadius) {
				goToMenu();
			}

		}
		void drawGame() {
			DrawCircle(p1.position.x, p1.position.y, p1.colliderRadius, RED);
			DrawCircle(e1.position.x, e1.position.y, e1.colliderRadius, BLUE);
		}
		void goToMenu() {
			menuspace::initMenu();
			currentstate = menustate;
		}
	}
}