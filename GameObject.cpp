// Outside imports
#include "stdafx.h"
#include <iostream>

// Linked to this header file
#include "GameObject.h"

GameObject::GameObject() {
}

void GameObject::update() {
	std::cout << "OBJ UPDATE" << std::endl;
}

void GameObject::clearObject() {
	delete this;
}