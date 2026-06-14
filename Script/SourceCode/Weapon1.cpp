#include "Weapon1.h"
#include"Player.h"

int Weapon1::LIFE;
float Weapon1::ATTACK_LENGHT;
float Weapon1::ATTACK_RADIUS;

Weapon1::Weapon1()
	:Weapon(Tag::ITEM)
{
	type = ItemType::WEAPON1;
	life = LIFE;
}

Weapon1::~Weapon1()
{}

void Weapon1::Draw()
{
	float sizeHalf = 10;
	Vector2 p1 = Vector2(position.x - sizeHalf, position.y - sizeHalf);
	Vector2 p2 = Vector2(position.x + sizeHalf, position.y + sizeHalf);

	DrawBox(p1.x, p1.y, p2.x, p2.y, COL_RED, TRUE);
	
	if (isAttack)
	{
		Vector2 start = position;
		Vector2 end = start + direction * ATTACK_LENGHT;
		DrawLine(start.x, start.y, end.x, end.y, COL_RED, ATTACK_RADIUS);
	}
}

void Weapon1::Attack(Player* owner)
{
	Vector2 stick = Input::GetStick(owner->GetId());
	if (stick != Vector2(0, 0))
	{
		owner->SetDir(Math2D::Normalize(stick));
		owner->ItemMove();
	}
	SetDir(owner->GetDir());

	if (Input::IsPadDown(Pad::A, owner->GetId()))
	{
		//ToDo : ここで攻撃の当たり判定用クラス生成
		life--;
		if (life <= 0)
		{
			owner->BrokenHasWeapon();
		}
	}
}

void Weapon1::EnhanceWeapon()
{
	//ToDo : ここで武器強化（パラメータを上昇させる）
}
