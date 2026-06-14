#pragma once
#include"Weapon.h"

class Weapon1 : public Weapon
{
public:
	Weapon1();
	~Weapon1();
	void Draw() override;
	void Attack() override;
};