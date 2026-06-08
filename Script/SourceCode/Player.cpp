#include "Player.h"
#include"Ui.h"

Player::Player()
	:Character(Tag::PLAYER)
{
	new Ui("カウント", &count);

	position = { WIN_WIDTH / 2,WIN_HEIGHT / 2 };
	velocity = { 0.0f,0.0f };

	//カプセル
	Vector2 start = { -70.0f,-70.0f };
	Vector2 end = { 70.0f,70.0f };
	uint32_t mask = (uint32_t)Layer::ENEMY2;
	myCollider.SetCapsule(start, end, 0.0f, Layer::PLAYER, mask);

	//ボックス
	start = { -40.0f,-40.0f };
	end = { 40.0f,40.0f };
	mask = (uint32_t)Layer::ENEMY;
	myCollider.SetBox(start, end, Layer::PLAYER, mask);

}

Player::~Player()
{}

void Player::Update()
{
	velocity = { 0.0f,0.0f };
	if (Input::IsKeepKeyDown(KEY_INPUT_W))
	{
		velocity.y = -10.0f;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_S))
	{
		velocity.y = 10.0f;
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		velocity.x = -10.0f;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		velocity.x = 10.0f;
	}
	position += velocity;
}

void Player::Draw()
{
	float x = position.x;
	float y = position.y;
	DrawCircle((int)x, (int)y, 20.0f, COL_WHITE, TRUE);
}

void Player::OnCollision(GameObject* other)
{
	count++;
}
