#ifndef BLOCK_H
#define BLOCK_H

#include "GameObject.h"
#include "CollisionBox.h"
#include "Player.h"

class Block: public GameObject{
private:
	sf::RenderWindow* renderWindow;
	std::vector<GameObject*>* activeObjects;
	sf::Sprite* sprite;
	sf::Texture* texture;

	CollisionBox* collisionBox;
	Player* player;

	int initialXpos;
	int initialYpos;
	int orientation;
	int xOffset;
	int yOffset;
	int orientationOffset;

public:
	Block(sf::RenderWindow* window, std::vector<GameObject*>* objectsList, Player* thePlayer);
	void update();
	void setOrigin(int x, int y);
	void setRotation(int r);
	void setPosition(int x, int y);
	bool visible;
	bool owned;
};

#endif