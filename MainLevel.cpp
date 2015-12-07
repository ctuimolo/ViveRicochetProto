// Outside imports
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

// Game Objects in this level
#include "Player.h"
#include "Block.h"

// Linked to this header file
#include "MainLevel.h"


MainLevel::MainLevel(sf::RenderWindow* window, RoomManager* manager) {
	renderWindow = window;
	roomManager = manager;

	//==== GAME OBJECTS VECTOR ====//
	/* GameObject type objects placed into this vector
	 * are placed through the update loop.
	 * game objects must have defined "update" funtions
	 */
	player = new Player(renderWindow);
	activeObjects.push_back(player);
}

void MainLevel::update() {
	// refresh screen for redrawing
	renderWindow->clear();

	// Active objects update loop
	int index = 0;
	for(std::vector<GameObject*>::iterator current = activeObjects.begin();
			current != activeObjects.end();) {
		GameObject* currentObject = activeObjects.at(index);
		currentObject->update();
		++current;
		++index;
	}

	// Spawn a block
	roomTime = roomClock.getElapsedTime().asSeconds();
	if(roomTime >= 5) {
		Block* newBlock = new Block(renderWindow, &activeObjects, player);
		activeObjects.push_back(newBlock);
		roomTime = 0;
		roomClock.restart();
	}

	// display screen update
	renderWindow->display();
}

void MainLevel::clearRoom() {
	int index = 0;
	// iterate over active objects and delete
	for(std::vector<GameObject*>::iterator current = activeObjects.begin(); 
			current != activeObjects.end();) {
		GameObject* currentObject = activeObjects.at(index);
		currentObject->clearObject();
		++current;
		++index;
	}
	activeObjects.clear();
}
