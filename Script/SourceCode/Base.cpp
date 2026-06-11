#include "Base.h"
#include"../Engine/Tool/ParamLoader.h"

Base::Base(Vector2 pos, int blockSize)
	:GameObject(Tag::STAGE)
{
	position = pos;

	uint32_t mask = (uint32_t)Layer::PLAYER;
	SetCenterBox(blockSize / 2, Layer::STAGE, mask);
}

Base::~Base()
{}
