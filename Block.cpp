// Outside imports
#include "stdafx.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// Objects used by this Block
#include "CollisionBox.h"

// Linked to this header file
#include "Block.h"

Block::Block(sf::RenderWindow* window, std::vector<GameObject*>* objectList, Player* thePlayer) {
	// The SFML window that this object interacts with
	renderWindow = window;

	// Pointer to vector of active objects
	activeObjects = objectList;

	// Player object this block can interact with
	player = thePlayer;

	// Initialize sprite & texture values
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("resources/redblock.png");
	sprite->setTexture(*texture);
	sprite->setOrigin(60, 12);

	// Initialize object values
	initialXpos = rand() % window->getSize().x;
	initialYpos = rand() % window->getSize().y;
	xpos = initialXpos;
	ypos = initialYpos;
	orientation = rand() % 360;
	visible = true;
	owned = false;

	// Create the visual representation of collision box (circle)
	collisionBox = new CollisionBox(renderWindow, xpos, ypos);
	activeObjects->push_back(collisionBox);
	
}

void Block::update() {

	if(!owned) {
		// Check collision with player
		if(player->xpos + player->collisionRadius > collisionBox->xpos - collisionBox->width/2 &&
		   player->xpos - player->collisionRadius < collisionBox->xpos + collisionBox->width/2 &&
		   player->ypos + player->collisionRadius > collisionBox->ypos - collisionBox->height/2 &&
		   player->ypos - player->collisionRadius < collisionBox->ypos + collisionBox->height/2) {
			owned = true;
			xOffset = player->xpos - collisionBox->xpos;
			yOffset = player->ypos - collisionBox->ypos;
			setOrigin(60 + xOffset, 12 + yOffset);
			orientationOffset = player->orientation;
		}
	}else {
		xpos = player->xpos;
		ypos = player->ypos;
		orientationOffset = player->orientation;
	}

	// Update block and it's collision box's position
	setPosition(xpos, ypos);
	setRotation(orientation + orientationOffset);

	// Keyboard event check to toggle visibility
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		visible = false;
	else visible = true;

	// Draw sprite(s) at the SFML window
	if(visible)	renderWindow->draw(*sprite);


}

void Block::setOrigin(int x, int y) {
	sprite->setOrigin(x, y);
	collisionBox->setOrigin(x, y);
}

void Block::setRotation(int r) {
	sprite->setRotation(r);
}

void Block::setPosition(int x, int y) {
	sprite->setPosition(xpos, ypos);
	collisionBox->setPosition(xpos, ypos);
}