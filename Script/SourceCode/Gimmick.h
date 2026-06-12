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
	virtual void Interact(Item* item) {}
protected:
	Item* hasItem = nullptr;
protected:
	static constexpr float INTERACT_LENGHT = 80.0f;
};