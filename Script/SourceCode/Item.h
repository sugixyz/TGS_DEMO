#pragma once
#include"../Engine/Object/GameObject.h"

class Item : public GameObject
{
public:
	Item(Tag tag)
		:GameObject(tag)
	{}
	~Item() {}
	void Draw() override;
};