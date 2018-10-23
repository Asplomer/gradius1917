#include "Gameplay.h"
namespace flowspace {
	namespace gameplayspace {
		player p1;
		enemy e1;
		Vector2 defaultPosition;
		Texture ship;
		Rectangle frameRec;
		Rectangle destRec;
		unsigned int framesCounter;
		float framesSpeed;
		unsigned int currentFrame;
		float shipScale;
		void initGame() {
			shipScale = 3;
			ship= LoadTexture("res/ShipSheet.png");
			frameRec = { 0.0f, 0.0f, (float)ship.width, (float)ship.height / 2 };
			destRec = {p1.position.x,p1.position.y, (float)ship.width * 2 *shipScale, (float)ship.height * shipScale};
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
			framesCounter = 0;
			currentFrame = 0;
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
			//---------ship animation----------------
			framesCounter++;
			framesSpeed = 0.15;

			if (framesCounter >= (60 / framesSpeed))
			{
				framesCounter = 0;
				currentFrame++;

				if (currentFrame > 1) currentFrame = 0;

				frameRec.y = (float)currentFrame*(float)ship.height / 2;
			}
			destRec = { p1.position.x,p1.position.y, (float)ship.width * 2 * shipScale, (float)ship.height * shipScale};

			//---------------collisions-----------------
			if (abs(p1.position.x - e1.position.x) < e1.colliderRadius && abs(p1.position.y - e1.position.y) < e1.colliderRadius) {
				goToMenu();
			}

		}
		void drawGame() {
			DrawCircle(p1.position.x, p1.position.y, p1.colliderRadius, RED);
			DrawTexturePro(ship, frameRec,destRec, { (float) ship.width / 2, (float) ship.height / 2}, 0.0f, WHITE);
			DrawCircle(e1.position.x, e1.position.y, e1.colliderRadius, BLUE);
		}
		void goToMenu() {
			UnloadTexture(ship);
			menuspace::initMenu();
			currentstate = menustate;
		}
	}
}