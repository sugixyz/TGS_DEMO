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
	virtual Item* Interact(Item* item) 
	{
		return nullptr;
	}
protected:
	Item* hasItem = nullptr;
protected:
	static constexpr float INTERACT_LENGHT = 60.0f;
};