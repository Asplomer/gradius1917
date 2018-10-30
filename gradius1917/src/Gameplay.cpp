#include "Gameplay.h"
namespace flowspace {
	namespace gameplayspace {
		Music bgm;
		player p1;
		Vector2 defaultPosition;
		Texture ship, scavenger;
		Texture foreground;
		Texture background;
		Rectangle frameRec, backRec, foreRec;
		Rectangle destRec, backScale, foreScale;
		Rectangle shipCollider;
		bool fireSwitch;
		bool won;
		unsigned int framesCounter;
		unsigned int bulletCounter = 0;
		float framesSpeed;
		float backSpeed;
		float foreSpeed;
		const float bulletSpeed = 3.0f;
		const float bulletRadius = 3.0f;
		unsigned int currentFrame;
		float shipScale;
		const int animationSpeed = 9;
		const int clipSize = 5;
		bullet bulletArray[clipSize];
		bullet auxBullet;
		const int maxEnemies = 5;
		int enemyCount;
		const int enemyDist = 30;
		unsigned const int timeToKill = 1;
		
		enemy e1[maxEnemies];
		void initGame() {
			bgm = LoadMusicStream("res/song3.ogg");
			shipScale = 1;
			ship = LoadTexture("res/ShipSheet.png");
			frameRec = { 0.0f, 0.0f, (float)ship.width, (float)ship.height / 4 };
			destRec = { p1.position.x,p1.position.y, (float)ship.width * 2 * shipScale, (float)ship.height / 2.0f * shipScale };
			shipCollider = { 0.0f,0.0f,(float)ship.width - (float)ship.width / 8 ,(float)ship.height / 2 - (float)ship.height / 4 };
			background = LoadTexture("res/Background.png");
			backRec = { 0.0f,0.0f, (float)background.width, (float)background.height };
			backScale = { (float)screenwidth / 2, (float)screenheight / 2, (float)screenwidth * 2.0f, (float)screenheight };
			foreground = LoadTexture("res/Foreground.png");
			foreRec = { 0.0f,0.0f, (float)foreground.width, (float)foreground.height };
			foreScale = { (float)screenwidth / 2, (float)screenheight / 2, (float)screenwidth * 2.0f, (float)screenheight };
			scavenger = LoadTexture("res/Scavenger.png");


			defaultPosition.x = 30;
			defaultPosition.y = screenheight / 2;
			p1.position = defaultPosition;
			p1.colliderRadius = 7.0;
			p1.hp = 3;
			p1.invulnerable = false;
			p1.lastInvulnerable = GetTime();
			for (int i = 0; i < clipSize; i++) {
				bulletArray[i].active = false;
			}

			for (int i = 0; i < maxEnemies; i++) {
				e1[i].active = true;
				e1[i].colliderRadius = 7.0;
				e1[i].acceleration = 400;
				e1[i].position.x = screenwidth - 30 - i * enemyDist;
				e1[i].position.y = GetRandomValue(10, screenheight - 10);
				e1[i].collisionRec = {e1[i].position.x,e1[i].position.y,(float)scavenger.width,(float)scavenger.height};
			}
			enemyCount = maxEnemies;
			p1.acceleration = 200;
			framesCounter = 0;
			currentFrame = 0;

			StopMusicStream(bgm);
			PlayMusicStream(bgm);
			SetMusicVolume(bgm, 1.0f);

		}
		void updateGame() {
			UpdateMusicStream(bgm);

			if (IsKeyDown(KEY_DOWN)) {
				p1.position.y += p1.acceleration * GetFrameTime();
			}
			if (IsKeyDown(KEY_UP)) {
				p1.position.y -= p1.acceleration * GetFrameTime();
			}
			if (IsKeyPressed(KEY_Q)) {
				goToMenu();
			}

			shipCollider.x = p1.position.x + 10;
			shipCollider.y = p1.position.y - 45;

			for (int i = 0; i < maxEnemies; i++) {
				if (e1[i].active) {
					e1[i].collisionRec.x = e1[i].position.x;
					e1[i].collisionRec.y = e1[i].position.y;
					e1[i].position.x -= e1[i].acceleration * GetFrameTime();
					if (e1[i].position.x <= 0) {
						e1[i].position.x = screenwidth - 30;
						e1[i].position.y = GetRandomValue(10, screenheight - 10);
					}
				}
			}
			//---------ship animation----------------
			framesCounter++;
			framesSpeed = 0.15;

			if (framesCounter >= (animationSpeed / framesSpeed))
			{
				framesCounter = 0;
				currentFrame++;

				if (currentFrame > 3) currentFrame = 0;

				frameRec.y = (float)currentFrame*(float)ship.height / 4;
			}
			destRec = { p1.position.x,p1.position.y,(float)ship.width * 2 * shipScale, (float)ship.height / 2.0f * shipScale };

			//---------------collisions-----------------

			if (!p1.invulnerable) {
				for (int i = 0; i < maxEnemies; i++){
					if (e1[i].active) {
						if (CheckCollisionRecs(shipCollider, e1[i].collisionRec)) {
							won = false;
							gameOver();
						}
					}
				}
			}

			/*invulnerability

			if (p1.invulnerable) {
				if (p1.lastInvulnerable < GetTime() + invuTime) {
					p1.invulnerable = false;
				}
			}*/

			//----------------------------------firing logic---------------------------

			if (IsKeyPressed(KEY_SPACE)) {
				fireSwitch = false;
				for (bulletCounter = 0; bulletCounter < clipSize; bulletCounter++) {
					if (!bulletArray[bulletCounter].active) {
						bulletArray[bulletCounter].position.x = p1.position.x + ship.width - 5;
						bulletArray[bulletCounter].position.y = p1.position.y -10;
						bulletArray[bulletCounter].active = true;
						bulletArray[bulletCounter].birthDate = GetTime();
						bulletArray[bulletCounter].colliderRadius = bulletRadius;
						bulletCounter = clipSize;
						fireSwitch = true;
					}

					if (!fireSwitch) {
						if (bulletCounter == clipSize) {
							for (int i = 0; i < clipSize - 1; i++)
							{
								auxBullet = bulletArray[i + 1];
								bulletArray[i + 1] = bulletArray[i];
							}
							bulletArray[0].position = p1.position;
							bulletArray[0].active = true;
							bulletArray[0].birthDate = GetTime();
							bulletArray[0].colliderRadius = bulletRadius;
							fireSwitch = true;
						}
					}
				}
			}

			for (int i = 0; i < clipSize; i++) {
				if (bulletArray[i].active) {
					bulletArray[i].position.x += bulletSpeed;
					if (GetTime() - bulletArray[i].birthDate > timeToKill) {
						bulletArray[i].active = false;
					}
				}
			}

			//----------------bullet->enemy collisions------
			for (int i = 0; i < clipSize; i++){
				if (bulletArray[i].active){
					for (int i2 = 0; i2 < maxEnemies; i2++){
						if (e1[i2].active) {
							if (CheckCollisionCircleRec(bulletArray[i].position, bulletRadius, e1[i2].collisionRec)) {
								bulletArray[i].active = false;
								e1[i2].active = false;
								enemyCount--;
							}
						}
					}
				}
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

			//----------------win logic------------------
			if (enemyCount <= 0){
				won = true;
				gameOver();
			}
		}



		//----------------------render----------------
		void drawGame() {
			DrawTexturePro(background, backRec, backScale, { (float)screenwidth,(float)screenheight / 2 }, 0.0f, WHITE);
			DrawTexturePro(foreground, foreRec, foreScale, { (float)screenwidth, (float)screenheight / 2 }, 0.0f, WHITE);
			/*if (p1.invulnerable) {
				if(p1.lastInvulnerable > GetTime() + invuTime / 4.0f || p1.lastInvulnerable < GetTime() + 3.0* invuTime / 4.0f){
					//DrawTexturePro(ship, frameRec, destRec, { (float)ship.width / 2, (float)ship.height / 2 }, 0.0f, WHITE);
				}
			}*/
			for (int i = 0; i < clipSize; i++) {
				if (bulletArray[i].active) {
					DrawCircle(bulletArray[i].position.x, bulletArray[i].position.y, bulletArray[i].colliderRadius, PURPLE);
				}
			}
			DrawTexturePro(ship, frameRec, destRec, { (float)ship.width / 2, (float)ship.height / 2 }, 0.0f, WHITE);
		
			for (int i = 0; i < maxEnemies; i++) {
				if (e1[i].active) {
					DrawTexture(scavenger, e1[i].position.x, e1[i].position.y, WHITE);
				}
			}

		}
		void goToMenu() {
			UnloadMusicStream(bgm);
			UnloadTexture(ship);
			UnloadTexture(scavenger);
			UnloadTexture(background);
			UnloadTexture(foreground);
			menuspace::initMenu();
			currentstate = menustate;
		}

		void gameOver() {
			UnloadMusicStream(bgm);
			UnloadTexture(ship);
			UnloadTexture(scavenger);
			UnloadTexture(background);
			UnloadTexture(foreground);
			gameoverspace::initGameOver();
			currentstate = gameoverstate;
		}
	}
}