#include "Table.h"

Table::Table(Vector2 pos)
	:Gimmick(Tag::GIMMICK)
{
	position = pos;

	uint32_t mask = (uint32_t)Layer::PLAYER;
	SetCenterCircle(INTERACT_LENGHT, Layer::GIMMICK, mask);
}

Table::~Table()
{}

void Table::Draw()
{
	float x = position.x - 64 / 2;
	float y = position.y - 64 / 2;
	DrawBox(x, y, x + 64, y + 64, COL_MAGENTA, TRUE);
}

void Table::Interact(Item* item)
{}
