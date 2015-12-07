#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include "GameObject.h"
#include "Player.h"

class CollisionBox: public GameObject{
private:
	sf::RenderWindow* renderWindow;
	Player* player;
	bool visible;

public:
	CollisionBox(sf::RenderWindow* window, int initialXpos, int initialYpos);
	int width;
	int height;
	sf::Vector2f origin;
	void update();
	void setPosition(int x, int y);
	void setOrigin(int x, int y);
	void setRotation(int r);
};

#endif