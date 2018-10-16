#include "Menu.h"
namespace flowspace {
	namespace menuspace {
		void initMenu() {
			startGame();
		}
		void updateMenu() {
		}
		void drawMenu() {
		}
		void exitGame() {
		}
		void startGame() {
			gameplayspace::initGame();
			currentstate = gameplaystate;
		}
	}
}