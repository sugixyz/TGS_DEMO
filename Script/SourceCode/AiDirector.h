#pragma once
#include"../Engine/Object/GameObject.h"

class AiDirector : public GameObject
{
public:
	AiDirector();
	~AiDirector();
	static void LoadParam();
private:
	void CreateStageObject();
	void CheckParam();
};