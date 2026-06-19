#include "Weapon3.h"
#include"Player.h"

int Weapon3::SWORD_NUMBER;
float Weapon3::ATTACK_RADIUS;
float Weapon3::MOVE_DISTANCE;
float Weapon3::MOVE_TIME;

Weapon3::Weapon3()
	:Weapon(Tag::ITEM)
{
	type = ItemType::WEAPON3;
	life = SWORD_NUMBER;
}

Weapon3::~Weapon3()
{}

void Weapon3::Draw()
{
	float sizeHalf = 10;
	Vector2 p1 = Vector2(position.x - sizeHalf, position.y - sizeHalf);
	Vector2 p2 = Vector2(position.x + sizeHalf, position.y + sizeHalf);

	DrawBox(p1.x, p1.y, p2.x, p2.y, COL_BLUE, TRUE);

	if (isAttack)
	{
	}
}

void Weapon3::Attack(Player * owner)
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
		Vector2 movePos = owner->GetPos() + owner->GetDir()* MOVE_DISTANCE;;
		owner->MoveAttack(movePos, MOVE_TIME);
		//ToDo : ここで当たり判定用クラスを生成
		life--;
		if (life <= 0)
		{
			owner->BrokenHasWeapon();
		}
	}

	owner->ItemMove();
}

void Weapon3::EnhanceWeapon()
{}
