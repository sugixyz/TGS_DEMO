#pragma once
#include"Attack.h"

class Slash : public Attack
{
public:
	Slash(Vector2 pos,Vector2 moveVec, float rad);
	~Slash();
	void Update() override;
	void Draw() override;
	//void OnCollision(GameObject* other) override;
	void IEDestroy();
private:
	Coroutine coroutine;
};