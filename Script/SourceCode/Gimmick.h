#pragma once
#include"../Engine/Object/GameObject.h"

class Item;

class Gimmick : public GameObject
{
public:
	Gimmick(Tag tag)
		:GameObject(tag)
	{}
	~Gimmick() {}
	virtual void Interact() {}
protected:
	Item* hasItem = nullptr;
};