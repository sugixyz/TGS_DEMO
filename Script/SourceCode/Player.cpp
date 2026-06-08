#include "Player.h"
#include"../Engine/Tool/ParamLoader.h"

int Player::MAX_HP;
float Player::SPEED;
Vector2 Player::SPAWN_POS_1;
Vector2 Player::SPAWN_POS_2;
float Player::RADIUS;

Player::Player(int index)
	:Character(Tag::PLAYER)
{
	id = index;
	position = SPAWN_POS_1;
	hp = MAX_HP;
	radius = RADIUS;
	direction = Math2D::UP;
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
	velocity = { 0,0 };
	if (Input::IsKeepKeyDown(KEY_INPUT_W))
	{
		direction = Math2D::UP;
		velocity = direction * SPEED;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_S))
	{
		direction = Math2D::DOWN;
		velocity = direction * SPEED;
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		direction = Math2D::LEFT;
		velocity = direction * SPEED;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		direction = Math2D::RIGHT;
		velocity = direction * SPEED;
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
			else if (key == "SPAWN_POS_1")  { ss >> SPAWN_POS_1.x >> SPAWN_POS_1.y; }
			else if (key == "SPAWN_POS_2")  { ss >> SPAWN_POS_2.x >> SPAWN_POS_2.y; }
			else if (key == "RADIUS")			{ ss >> RADIUS; }
		}
	);
}
