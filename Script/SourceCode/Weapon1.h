#pragma once
#include"Weapon.h"

//銃器（レーザー）
class Weapon1 : public Weapon
{
public:
	Weapon1();
	~Weapon1();
	void Draw() override;
	void Attack(Player* owner) override;
	void EnhanceWeapon() override;
public:
	static int LIFE;
	static float ATTACK_LENGHT;
	static float ATTACK_RADIUS;
};