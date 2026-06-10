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
	void CollisionWall(GameObject* other);
private:
	static int MAX_HP;
	static float SPEED;
	static Vector2 SPAWN_POS[2];
	static float RADIUS;
};