#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject{
public:
	GameObject();
	virtual void update();
	virtual void clearObject();
	int xpos;
	int ypos;
};

#endif