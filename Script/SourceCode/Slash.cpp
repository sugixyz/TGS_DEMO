#include "Slash.h"

Slash::Slash(GameObject* pl, float rad, float sec)
	:Attack(Tag::ATTACK)
{
	owner = pl;
	position = owner->GetPos();
	radius = rad;
	time = sec;

	uint32_t mask = (uint32_t)Layer::ENEMY | (uint32_t)Layer::STAGE;
	SetCenterCircle(Layer::PLAYER_ATTACK, mask);
}

Slash::~Slash()
{}

void Slash::Update()
{
	dethTimer.Update();
	position = owner->GetPos();
	if (dethTimer.isExpired(time))
	{
		DestroyMe();
	}
}

void Slash::Draw()
{
	DrawCircle(position.x, position.y, radius, COL_BLACK, TRUE);
}

void Slash::OnCollision(GameObject* other)
{
	DestroyMe();
}

