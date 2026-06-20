#pragma once
#include"Attack.h"

class Slash : public Attack
{
public:
	Slash(GameObject* pl, float rad, float sec);
	~Slash();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
private:
	GameObject* owner;
	Timer dethTimer;
	float time;
};