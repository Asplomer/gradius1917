#include "Gameplay.h"
namespace flowspace {
	namespace gameplayspace {
		player p1;
		enemy e1;
		Vector2 defaultPosition;
		Texture ship, scavenger;
		Texture foreground;
		Texture background;
		Rectangle frameRec, backRec, foreRec;
		Rectangle destRec, backScale, foreScale;
		Rectangle shipCollider;
		unsigned int framesCounter;
		float framesSpeed;
		float backSpeed;
		float foreSpeed;
		unsigned int currentFrame;
		float shipScale;
		void initGame() {
			shipScale = 1;
			ship= LoadTexture("res/ShipSheet.png");
			frameRec = { 0.0f, 0.0f, (float)ship.width, (float)ship.height / 2 };
			destRec = {p1.position.x,p1.position.y, (float)ship.width * 2 *shipScale, (float)ship.height * shipScale};
			shipCollider = {0.0f,0.0f,(float)ship.width - (float)ship.width/ 8 ,(float)ship.height/2 - (float)ship.height / 4};
			background = LoadTexture("res/Background.png");
			backRec = {0.0f,0.0f, (float)background.width, (float)background.height};
			backScale = {(float)screenwidth / 2, (float) screenheight / 2, (float)screenwidth * 2.0f, (float)screenheight};
			foreground = LoadTexture("res/Foreground.png");
			foreRec = { 0.0f,0.0f, (float)foreground.width, (float)foreground.height};
			foreScale = { (float)screenwidth / 2, (float)screenheight / 2, (float)screenwidth * 2.0f, (float)screenheight};
			scavenger = LoadTexture("res/Scavenger.png");


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

			shipCollider.x = p1.position.x + 10;
			shipCollider.y = p1.position.y -6;

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

			//----------------parallax------------------
			if (backScale.x <= 0) {
				backScale.x = screenwidth;
			}
			backScale.x -= 20 * GetFrameTime();
			if (foreScale.x <= 0) {
				foreScale.x = screenwidth;
			}
			foreScale.x -= 60 * GetFrameTime();
		}
		void drawGame() {
			DrawTexturePro(background, backRec, backScale,{ (float)screenwidth,(float)screenheight/2}, 0.0f, WHITE);
			DrawTexturePro(foreground, foreRec, foreScale, {(float)screenwidth, (float)screenheight/2}, 0.0f, WHITE);
			DrawTexturePro(ship, frameRec,destRec, { (float) ship.width / 2, (float) ship.height / 2}, 0.0f, WHITE);
			DrawCircle(p1.position.x, p1.position.y, p1.colliderRadius, BLUE);
			DrawRectangleRec(shipCollider,WHITE);
			DrawTexture(scavenger, e1.position.x, e1.position.y, WHITE);
			DrawCircle(e1.position.x, e1.position.y, e1.colliderRadius, BLUE);
		}
		void goToMenu() {
			UnloadTexture(ship);
			UnloadTexture(scavenger);
			UnloadTexture(background);
			UnloadTexture(foreground);
			menuspace::initMenu();
			currentstate = menustate;
		}
	}
}