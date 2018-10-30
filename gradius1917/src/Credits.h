#ifndef CREDITS_H
#define CREDITS_H
#include "FlowManager.h"
#include "Gameplay.h"
#include "Menu.h"
#include "raylib.h"
namespace flowspace {
	namespace creditsspace {
		void initCredits();
		void updateCredits();
		void drawCredits();
		void goToMenu();
	}
}
#endif