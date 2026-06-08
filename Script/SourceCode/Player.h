#pragma once
#include"../Engine/Object/Character.h"

class Player : public Character
{
public:
	Player(int index);
	~Player();
	void Update() override;
	void Draw() override;
	void Move() override;
	void OnCollision(GameObject* other) override;
	static void LoadParam();
private:
	int hp;
	int id;
private:
	static int MAX_HP;
	static float SPEED;
	static Vector2 SPAWN_POS_1;
	static Vector2 SPAWN_POS_2;
	static float RADIUS;
};