#include "Base.h"
#include"../Engine/Tool/ParamLoader.h"

Base::Base(Vector2 pos, int blockSize)
	:GameObject(Tag::STAGE)
{
	position = pos + Vector2(blockSize / 2, blockSize / 2);

	Vector2 p1 = Vector2((float)-blockSize / 2, (float)-blockSize / 2);
	Vector2 p2 = Vector2((float)blockSize / 2, (float)blockSize / 2);
	uint32_t mask = (uint32_t)Layer::PLAYER;
	SetBox(p1, p2, Layer::STAGE, mask);
}

Base::~Base()
{}
