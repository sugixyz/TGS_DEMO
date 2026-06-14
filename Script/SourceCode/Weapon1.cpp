#include "Weapon1.h"

Weapon1::Weapon1()
	:Weapon(Tag::ITEM)
{
	type = ItemType::WEAPON1;

}

Weapon1::~Weapon1()
{}

void Weapon1::Draw()
{
	float sizeHalf = 10;
	Vector2 p1 = Vector2(position.x - sizeHalf, position.y - sizeHalf);
	Vector2 p2 = Vector2(position.x + sizeHalf, position.y + sizeHalf);

	DrawBox(p1.x, p1.y, p2.x, p2.y, COL_RED, TRUE);
}

void Weapon1::Attack()
{
}
