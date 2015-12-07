#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player: public GameObject{
private:
	sf::RenderWindow* renderWindow;
	sf::Sprite* sprite;
	sf::Texture* texture;

	int initialXpos;
	int initialYpos;
	int speed;
	int rotateSpeed;

public:
	Player(sf::RenderWindow* window);
	void update();
	int collisionRadius;
	int orientation;
};

#endif