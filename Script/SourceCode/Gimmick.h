#pragma once
#include"../Engine/Object/GameObject.h"

class Gimmick : public GameObject
{
public:
	Gimmick(Tag tag)
		:GameObject(tag)
	{}
	~Gimmick() {}

};