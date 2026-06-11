#pragma once
#include"Gimmick.h"

class CraftTable : public Gimmick
{
public:
	CraftTable(Vector2 pos);
	~CraftTable();
	void Draw() override;
	void Interact() override;
};