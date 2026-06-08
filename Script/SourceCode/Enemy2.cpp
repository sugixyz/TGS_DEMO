#include "Enemy2.h"

Enemy2::Enemy2()
	:Character(Tag::ENEMY)
{
	position = { (float)GetRand(WIN_WIDTH),(float)GetRand(WIN_HEIGHT) };
	velocity = { 0.0f,0.0f };

	//ボックス
	Vector2 start = { -30.0f,-30.0f };
	Vector2 end = { 30.0f,30.0f };
	uint32_t mask = (uint32_t)Layer::PLAYER;
	myCollider.SetBox(start, end, Layer::ENEMY2, mask);
}

Enemy2::~Enemy2()
{}

void Enemy2::Update()
{}

void Enemy2::Draw()
{
	Vector2 p1 = position + Vector2(-20.0f, -20.0f);
	Vector2 p2 = position + Vector2(20.0f, 20.0f);

	DrawBox((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, COL_GREEN, TRUE);
}

void Enemy2::OnCollision(GameObject* other)
{
	DestroyMe();
}
