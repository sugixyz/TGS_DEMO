#pragma once
#include"../Engine/Object/Character.h"

class Player : public Character
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
private:
	int count = 0;
};