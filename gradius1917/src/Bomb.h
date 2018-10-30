#ifndef BOMB_H
#define BOMB_H
#include <iostream>
#include "raylib.h"
#include "Gameplay.h"
#include "FlowManager.h"
namespace flowspace {

	const int BOMBSPEED = 50;
	
	void InitBomb(Vector2 pos);
	void SetShot(bool sho);
	bool GetShot();
	void DrawBullet();
	//Rectangle GetRect();
	void UpdateBomb(Vector2 ship);
};
#endif 

