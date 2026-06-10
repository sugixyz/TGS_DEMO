#include "AiDirector.h"
#include"Player.h"

AiDirector::AiDirector()
	:GameObject(Tag::SYSTEM)
{
	new Player(0);
	new Player(1);
}

AiDirector::~AiDirector()
{}

//ToDo :パラメーターローダー追加
//オブジェクトの数を取得
//オブジェクトの数分繰り返し
//取得したポジション、回転、スケールと、for分の値を引数にオブジェクトを生成
