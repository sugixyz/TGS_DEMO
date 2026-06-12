#include "CraftTable.h"

CraftTable::CraftTable(Vector2 pos)
	:Gimmick(Tag::GIMMICK)
{
	position = pos;

	uint32_t mask = (uint32_t)Layer::PLAYER;
	SetCenterCircle(INTERACT_LENGHT, Layer::GIMMICK, mask);
}

CraftTable::~CraftTable()
{}

void CraftTable::Draw()
{
	float x = position.x - 64 / 2;
	float y = position.y - 64 / 2;
	DrawBox(x, y, x + 64, y + 64, COL_CYAN, TRUE);
}

void CraftTable::Interact(Item* item)
{}
