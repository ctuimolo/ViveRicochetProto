#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

class Room;

class RoomManager {
private:
	Room* currentRoom;

public:
	RoomManager();
	void update();
	void changeRoom(Room* nextRoom);
};

/////////////////////////

class Room{
private:
	sf::RenderWindow* renderWindow;

public:
	Room();
	virtual void update();
	void clearRoom();
};

#endif