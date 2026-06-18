#include "Bomb.h"

Bomb::Bomb(Vector2 start, Vector2 end, float rad,float time)
	:Attack(Tag::ATTACK)
{
	radius = rad;
	moveLerp.Start(start, end, time, [this](Vector2 pos) {SetPos(pos); });
}

Bomb::~Bomb()
{}

void Bomb::Update()
{
	coroutine.Update();
	Move();
	CheckOutRange();
}

void Bomb::Draw()
{
	float x = position.x;
	float y = position.y;
	DrawCircle(x, y, 15, COL_BLACK, TRUE);
}

void Bomb::Move()
{
	moveLerp.Update();
	if (not moveLerp.IsActive())
	{
		uint32_t mask = (uint32_t)Layer::ENEMY;
		SetCenterCircle(Layer::PLAYER_ATTACK, mask);
		coroutine.Start([this] {IEDestroy(); });
	}
}

void Bomb::IEDestroy()
{
	DestroyMe();
}
