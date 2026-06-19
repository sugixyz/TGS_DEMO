#include "Slash.h"

Slash::Slash(Vector2 pos, Vector2 moveVec, float rad)
	:Attack(Tag::ATTACK)
{
	position = pos + moveVec;
	radius = rad;

	Vector2 st = { 0,0 };
	uint32_t mask = (uint32_t)Layer::ENEMY | (uint32_t)Layer::STAGE;
	SetCapsule(st, moveVec * -1, rad, Layer::PLAYER_ATTACK, mask);
}

Slash::~Slash()
{}

void Slash::Update()
{
	coroutine.Update();
	coroutine.Start([this] {IEDestroy();});
}

void Slash::Draw()
{
	DrawCircle(position.x, position.y, radius, COL_BLACK, TRUE);
}

void Slash::IEDestroy()
{
	DestroyMe();
}
