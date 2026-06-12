#include "Material.h"

Material::Material(int id)
	:Item(Tag::ITEM)
{
	if (id == 1)type = ItemType::MATERIAL1;
	else if (id == 2)type = ItemType::MATERIAL2;
}

Material::~Material()
{
}

void Material::Draw()
{
	float x = position.x;
	float y = position.y;

	DrawCircle(x, y, 10, COL_WHITE, TRUE);
}
