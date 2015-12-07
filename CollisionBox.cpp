// Outside imports
#include "stdafx.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// Linked to this header file
#include "CollisionBox.h"


CollisionBox::CollisionBox(sf::RenderWindow* window, int initialXpos, int initialYpos) {
	// The SFML window that this object interacts with
	renderWindow = window;

	// Initialize object values
	xpos = initialXpos;
	ypos = initialYpos;
	width = 14;
	height = 14;
	origin.x = width/2;
	origin.y = height/2;
	visible = false;
}

void CollisionBox::update() {

	// Update box's position
	setPosition(xpos, ypos);

	// Draw sprite(s) at the SFML window
	// Keyboard event check to toggle visibility
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		visible = true;
	else visible = false;

	if(visible) {
		// Draw sprite(s) at the SFML window
		sf::RectangleShape box;
		box.setFillColor(sf::Color(255, 255, 255, 128));
		box.setOrigin(origin.x, origin.y);
		box.setSize(sf::Vector2f(width, height));
		box.setPosition(xpos, ypos);
		renderWindow->draw(box);	
	}
}

void CollisionBox::setOrigin(int x, int y) {
	origin.x = x;
	origin.y = y;
}


void CollisionBox::setPosition(int x, int y) {
	xpos = x;
	ypos = y;
}

void CollisionBox::setRotation(int r) {
}