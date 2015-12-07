// Outside imports
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

// Linked to these header files
#include "RoomManager.h"

RoomManager::RoomManager() {
}

void RoomManager::update() {
	if(currentRoom != nullptr) {
		currentRoom->update();
	}
	else {
		std::cout << "ERR: no room\n";
	}
}
void RoomManager::changeRoom(Room* nextRoom) {
	currentRoom = nextRoom;
}

///////////////////////////////////////////////

Room::Room() {
}

void Room::update() {
	std::cout << "OBJ UPDATE" << std::endl;
}