#include "Player.h"
#include"../Engine/Tool/ParamLoader.h"
#include"Weapon.h"
#include"Gimmick.h"

int Player::MAX_HP;
float Player::SPEED;
Vector2 Player::SPAWN_POS[2];
float Player::RADIUS;

Player::Player(int index)
	:Character(Tag::PLAYER)
{
	id = index;
	position = SPAWN_POS[id];
	hp = MAX_HP;
	radius = RADIUS;
	direction = Math2D::UP;

	uint32_t mask = (uint32_t)Layer::STAGE | (uint32_t)Layer::GIMMICK;
	SetCenterCircle(Layer::PLAYER, mask);
}

Player::~Player()
{}

void Player::Update()
{
	if (Attack())return;
	Move();
	Interact();

}

void Player::Draw()
{
	int x = (int)position.x;
	int y = (int)position.y;

	DrawCircle(x, y, radius, COL_WHITE, TRUE);

	Vector2 dirPos = { x + direction.x * radius,y + direction.y * radius };
	DrawLine(x, y, dirPos.x, dirPos.y, COL_RED);
}

void Player::Move()
{
	Vector2 stick = Input::GetStick(id);
	if (stick != Vector2(0, 0))
	{
		direction = Math2D::Normalize(stick);
		if (Math2D::Length(stick) >= 0.5f)
		{
			velocity = direction * SPEED;
		}
	}
	else
	{
		velocity = { 0,0 };
	}

	position += velocity;

	if (hasItem != nullptr)
	{
		hasItem->SetPos(Vector2(position + direction * 20));
	}
}

void Player::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::STAGE)
	{
		CollisionWall(other);
	}
	if (other->GetTag() == Tag::GIMMICK)
	{
		CollisionGimmick(other);
	}
}

void Player::CollisionWall(GameObject* wall)
{
	Collider wallCol = wall->GetCollider();
	Vector2 wPos = wall->GetPos();
	//壁の高さ、幅
	float wallW = wallCol.bPosB.x - wallCol.bPosA.x;
	float wallH = wallCol.bPosB.y - wallCol.bPosA.y;

	float overlapX = (this->radius + wallW / 2.0f) - abs(this->position.x - wPos.x);
	float overlapY = (this->radius + wallH / 2.0f) - abs(this->position.y - wPos.y);

	//当たったのが左右の壁なら
	if (overlapX < overlapY)
	{
		//壁が右にあるなら
		if (this->position.x < wPos.x)
		{
			this->position.x -= overlapX;
		}
		//壁が左にあるなら
		else
		{
			this->position.x += overlapX;
		}
	}
	//当たったのが上下の壁なら
	else
	{
		//壁が上にあるなら
		if (this->position.y < wPos.y)
		{
			this->position.y -= overlapY;
		}
		//壁が下にあるなら
		else
		{
			this->position.y += overlapY;
		}
	}
}

void Player::CollisionGimmick(GameObject* other)
{
	if (interactionGimmick == nullptr)
	{
		interactionGimmick = other;
		return;
	}

	float iLenghtSq = Math2D::LengthSq(position - interactionGimmick->GetPos());
	float gLenghtSq = Math2D::LengthSq(position - other->GetPos());

	if (iLenghtSq > gLenghtSq)interactionGimmick = other;
}

void Player::Interact()
{
	if (Input::IsPadDown(Pad::A, id))
	{
		//もし適応可能なギミックがなければスルー
		if (interactionGimmick == nullptr)return;

		Gimmick* g = dynamic_cast<Gimmick*>(interactionGimmick);
		hasItem = g->Interact(hasItem);
	}
	//毎フレーム初期化
	interactionGimmick = nullptr;
}

bool Player::Attack()
{
	//RBを押しているなら攻撃できるかチェック
	if (Input::IsKeepPadDown(Pad::RB, id))
	{
		Weapon* wpn = dynamic_cast<Weapon*>(hasItem);

		//もし持っているアイテムが武器なら攻撃
		if (wpn != nullptr)
		{
			wpn->Attack();
			return true;
		}
	}
	return false;
}
