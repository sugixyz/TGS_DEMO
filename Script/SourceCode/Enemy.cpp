#include "Enemy.h"

Enemy::Enemy()
	:Character(Tag::ENEMY)
{
	position = { (float)GetRand(WIN_WIDTH),(float)GetRand(WIN_HEIGHT) };
	velocity = { 0.0f,0.0f };

	//カプセル
	Vector2 start = { 20.0f,20.0f };
	Vector2 end = { -20.0f,-20.0f };
	uint32_t mask = (uint32_t)Layer::PLAYER;
	myCollider.SetCapsule(start, end, 30.0f, Layer::ENEMY, mask);
}

Enemy::~Enemy()
{}

void Enemy::Update()
{}

void Enemy::Draw()
{
	float x = position.x;
	float y = position.y;
	DrawCircle((int)x, (int)y, 20.0f, COL_RED, TRUE);
}

void Enemy::OnCollision(GameObject* other)
{
	if (other->GetTag() == Tag::PLAYER)
	{
		DestroyMe();
	}
}
