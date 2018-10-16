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
			e1.position.x = screenwidth - 30;
			e1.position.y = screenheight / 2;
			e1.active = true;
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
			e1.position.x -= e1.acceleration * GetFrameTime();
			if (e1.position.x <= 0) {
				e1.position.x = screenwidth - 30;
				e1.position.y = GetRandomValue(10,screenheight-10);
			}
		}
		void drawGame() {
			DrawCircle(p1.position.x, p1.position.y, 7.0, RED);
			DrawCircle(e1.position.x, e1.position.y, 7.0, BLUE);
		}
		void goToMenu() {
		}
	}
}