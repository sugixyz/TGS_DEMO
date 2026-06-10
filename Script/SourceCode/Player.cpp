#include "Player.h"
#include"../Engine/Tool/ParamLoader.h"

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

	//SPEED = 0;
}

Player::~Player()
{}

void Player::Update()
{
	Move();
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
}

void Player::OnCollision(GameObject * other)
{}

void Player::LoadParam()
{
	char path[50] = "Assets/ParamText/Player.txt";
	Loader::SetParam(path, [](const std::string& key, std::stringstream& ss)
		{
			if (key == "MAX_HP")			{ ss >> MAX_HP; }
			else if (key == "SPEED")		{ ss >> SPEED; }
			else if (key == "SPAWN_POS_1")  { ss >> SPAWN_POS[0].x >> SPAWN_POS[0].y; }
			else if (key == "SPAWN_POS_2")  { ss >> SPAWN_POS[1].x >> SPAWN_POS[1].y; }
			else if (key == "RADIUS")			{ ss >> RADIUS; }
		}
	);
}
