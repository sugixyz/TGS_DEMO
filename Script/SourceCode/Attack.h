#pragma once
#include"../Engine/Object/Character.h"

class Attack : public Character
{
public:
	Attack(Tag tag)
		:Character(tag)
	{}
	~Attack() {}
};