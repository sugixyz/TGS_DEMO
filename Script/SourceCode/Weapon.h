#pragma once
#include"Item.h"

class Weapon : public Item
{
public:
	Weapon(Tag tag)
		:Item(tag)
	{
	}
	~Weapon() {}
	/// <summary>
	/// 攻撃用の仮想関数
	/// </summary>
	virtual void Attack() {}
};