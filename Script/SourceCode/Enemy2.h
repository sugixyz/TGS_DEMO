#pragma once
#include"../Engine/Object/Character.h"

class Enemy2 : public Character
{
public:
	Enemy2();
	~Enemy2();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
};