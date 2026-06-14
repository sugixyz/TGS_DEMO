#pragma once
#include"../Engine/Object/Character.h"

class Item;

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
	//１Pか２Pか
	int id;
	//持っているアイテム
	Item* hasItem = nullptr;
	//インタラクト可能なギミック
	GameObject* interactionGimmick = nullptr;
private:
	//壁と接触したときの処理
	void CollisionWall(GameObject* other);
	//ギミックと接触したときの処理
	void CollisionGimmick(GameObject* other);
	//ギミックのインタラクト
	void Interact();
	//攻撃（攻撃中ならtrueを返す）
	bool Attack();
private:
	static int MAX_HP;
	static float SPEED;
	static Vector2 SPAWN_POS[2];
	static float RADIUS;
};