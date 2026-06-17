#include "Weapon2.h"
#include"Player.h"

float Weapon2::ATTACK_RANGE;
float Weapon2::ATTACK_RADIUS;
float Weapon2::FALL_TIME;

Weapon2::Weapon2()
	:Weapon(Tag::ITEM)
{
	type = ItemType::WEAPON1;
	life = 1;
	//初期は攻撃範囲上限の半分に
	range = ATTACK_RANGE / 2;
}

Weapon2::~Weapon2()
{}

void Weapon2::Draw()
{
	float sizeHalf = 10;
	Vector2 p1 = Vector2(position.x - sizeHalf, position.y - sizeHalf);
	Vector2 p2 = Vector2(position.x + sizeHalf, position.y + sizeHalf);

	DrawBox(p1.x, p1.y, p2.x, p2.y, COL_GREEN, TRUE);

	if (isAttack)
	{
		float x = attackPos.x;
		float y = attackPos.y;
		DrawCircle(x, y, ATTACK_RADIUS, COL_RED, TRUE);
	}
}

void Weapon2::Attack(Player * owner)
{
	//最初に攻撃位置を初期化
	if (!isAttack)
	{
		attackPos = position + owner->GetDir() * range;
	}

	Vector2 stick = Input::GetStick(owner->GetId());
	if (stick != Vector2(0, 0))
	{
		//スティックの方向に攻撃位置を変化させる
		Vector2 dir = Math2D::Normalize(stick);
		attackPos += dir * 10;
		range = Math2D::LengthSq(attackPos - position);
		if (range > ATTACK_RANGE * ATTACK_RANGE)
		{
			range = ATTACK_RANGE;
			attackPos = position + dir * range;
		}
		owner->SetDir(dir);
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

void Weapon2::EnhanceWeapon()
{}
