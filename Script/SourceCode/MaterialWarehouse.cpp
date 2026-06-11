#include "MaterialWarehouse.h"

MaterialWarehouse::MaterialWarehouse(Vector2 pos,int id)
	:Gimmick(Tag::GIMMICK)
{
	position = pos;
	materialId = id;
}

MaterialWarehouse::~MaterialWarehouse()
{}

void MaterialWarehouse::Draw()
{
	unsigned int col = COL_WHITE;
	if(materialId == 1)col = COL_YELLOW;
	if(materialId == 2)col = COL_BLUE;
	float x = position.x - 64 / 2;
	float y = position.y - 64 / 2;
	DrawBox(x, y, x + 64, y + 64, col, TRUE);
}

void MaterialWarehouse::Interact()
{}
