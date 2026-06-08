#pragma once
#include"../Engine/Object/Character.h"

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
};