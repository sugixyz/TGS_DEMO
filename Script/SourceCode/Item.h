#pragma once
#include"../Engine/Object/GameObject.h"

enum ItemType : uint32_t
{
	MATERIAL1 = 1 << 0,
	MATERIAL2 = 1 << 1,
	MATERIAL_ENEMY = 1 << 2,
	WEAPON1 = 1 << 3,
	WEAPON2 = 1 << 4,
	WEAPON3 = 1 << 5,
	ENHANCED_WEAPON1 = 1 << 6,
	ENHANCED_WEAPON2 = 1 << 7,
	ENHANCED_WEAPON3 = 1 << 8
};

class Item : public GameObject
{
public:
	Item(Tag tag)
		:GameObject(tag)
	{}
	~Item() {}
	void Draw() override {}
	/// <summary>
	/// このアイテムが武器かどうか
	/// </summary>
	/// <returns>武器であればtrue</returns>
	bool IsWeapon() { return isWeapon; }
	/// <summary>
	/// アイテムのタイプを取得
	/// </summary>
	/// <returns>アイテムのタイプを返す</returns>
	ItemType GetItemType() { return type; }
	/// <summary>
	/// 武器用の仮想関数（外部からアタックにアクセスするため）
	/// </summary>
	virtual void Attack() {}
protected:
	//このアイテムが武器かどうか
	bool isWeapon;
	ItemType type;
};