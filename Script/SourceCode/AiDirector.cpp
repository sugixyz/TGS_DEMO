#include "AiDirector.h"
#include"Player.h"

AiDirector::AiDirector()
	:GameObject(Tag::SYSTEM)
{
	new Player(1);
}

AiDirector::~AiDirector()
{}
