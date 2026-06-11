#include "MaterialWarehouse.h"

namespace
{

}

MaterialWarehouse::MaterialWarehouse(Vector2 pos, int blockSize,int id)
	:Gimmick(Tag::GIMMICK)
{
	position = pos + Vector2(blockSize / 2, blockSize / 2);
	materialId = id;
}

MaterialWarehouse::~MaterialWarehouse()
{}

void MaterialWarehouse::Draw()
{
	unsigned int col;
	if(materialId == 2)col = COL_YELLOW;
	if(materialId == 3)col = COL_BLUE;
	float x = position.x - 64 / 2;
	float y = position.y - 64 / 2;
	DrawBox(x, y, x + 64, y + 64, col, TRUE);
}

void MaterialWarehouse::Interact()
{}
