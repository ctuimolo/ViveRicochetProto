#ifndef MAINLEVEL_H
#define MAINLEVEL_H

#include "RoomManager.h"

class MainLevel: public Room{
private:
	sf::RenderWindow* renderWindow;
	RoomManager* roomManager;
	std::vector<GameObject*> activeObjects;

	sf::Clock roomClock;
	int roomTime;
	Player* player;

public:
	MainLevel(sf::RenderWindow* window, RoomManager* manager);
	void update();
	void clearRoom();
};

#endif