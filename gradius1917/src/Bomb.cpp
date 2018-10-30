#include "Bomb.h"

namespace flowspace {
	using namespace gameplayspace;
	static bomb b;
	static float rotation;
	void InitBomb(Vector2 pos) {
		b.shot = false;
		b.position = {pos.x, pos.y};
		b.lifetime = 0.0f;
		b.timeToDie = 5.0f;
		b.bombRadius = 3.0f;
		b.speedX = 5.0f;
		b.speedY = 0.0f;
		b.bombTexture = LoadTexture("res/Bomb.png");
		rotation = 270.0f;

	}
	void SetShot(bool sho) {
		b.shot = sho;
	}
	bool GetShot() {
		return b.shot;
	}
	void DrawBullet(){
		DrawTextureEx(b.bombTexture, b.position, rotation, 1.0f, WHITE);
	}
	void UpdateBomb(Vector2 ship) {


	}


}
