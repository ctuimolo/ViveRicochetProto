// Outside imports
#include "stdafx.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// Linked to this header file
#include "Player.h"


Player::Player(sf::RenderWindow* window) {
	// The SFML window that this object interacts with
	renderWindow = window;

	// Initialize sprite & texture values
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("resources/homu.png");
	sprite->setTexture(*texture);

	sprite->setOrigin(texture->getSize().x/2, texture->getSize().y/2);

	// Initialize object values
	initialXpos = window->getSize().x/2;
	initialYpos = window->getSize().y/2;
	xpos = initialXpos;
	ypos = initialYpos;
	speed = 3;
	orientation = 0;
	rotateSpeed = 5;
	collisionRadius = 20;
}

void Player::update() {

	// On key press, do action
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		ypos -= speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		ypos += speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		xpos -= speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		xpos += speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		orientation -= rotateSpeed % 360;
		sprite->setRotation(orientation);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		orientation += rotateSpeed % 360;
		sprite->setRotation(orientation);
	}

	// Update player position
	sprite->setPosition(xpos, ypos);
	// Draw sprite at the SFML window
	renderWindow->draw(*sprite);
}