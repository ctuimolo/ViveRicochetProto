///////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////

// Imported influences (i.e. SFML, VisualStudio stuff, etc.)
#include "stdafx.h"
#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>

// Game engine constructs
#include "GameObject.h"
#include "RoomManager.h"
#include "CollisionBox.h"

// Rooms/Levels to load at start
#include "MainLevel.h"

///////////////////////////////////////////////////////
// Entry point of application
///////////////////////////////////////////////////////

int main() {

	//==== GAME CONSTANTS & INITS ====//
	const int gameWidth = 600;
	const int gameHeight = 600;

	//==== INITIALIZE GAME WINDOW ====//
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "ViveRicochet - Proto", 
		sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	//==== INITIALIZE ROOM MANAGER & FIRST ROOM ====//
	/* THe room manager calls the current room's update
	 * function from the main loop.
	 */
	RoomManager* roomManager = new RoomManager();
	Room* mainLevel = new MainLevel(&window, roomManager);
	roomManager->changeRoom(mainLevel);

	//==== MAIN LOOP ====//
	while (window.isOpen()) {

		// Call room manager update
		roomManager->update();

		// Events handled by SFML library
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
	}
}