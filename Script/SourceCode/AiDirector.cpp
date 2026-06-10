#include "AiDirector.h"
#include"Player.h"
#include"../Engine/Tool/ParamLoader.h"
#include"StageObject.h"

AiDirector::AiDirector()
	:GameObject(Tag::SYSTEM)
{
	new Player(0);
	new Player(1);
	CreateStageObject();
}

AiDirector::~AiDirector()
{}

void AiDirector::LoadParam()
{

}

void AiDirector::CreateStageObject()
{
	char path[50] = "Assets/StageObject/ObjectData.txt";
	std::ifstream file(path);
	//ファイルがなければスルー
	if (!file.is_open())return;

	std::string line;
	int objNum = 0;
	int BaseBlockSize = 0;
	while (std::getline(file, line))
	{
		//もし空行か、コメントだったらスルー
		if (line.empty() || line.rfind("//", 0) == 0)continue;
		//文字が入っていればチェックをしてループを抜ける
		std::stringstream ss(line);
		std::string key, eq;
		if (ss >> key >> eq)
		{
			if (key == "OBJ_NUM") { ss >> objNum; }
			else if(key == "BASE_BLOCK")
			{
				ss >> BaseBlockSize;
				break;
			}
		}
	}
	int id = 0;
	Vector3 pos;
	Vector3 rot;
	Vector3 sca;
	//オブジェクトの数分ループ
	for (int i = 0; i < objNum; i++)
	{
		while (std::getline(file, line))
		{
			//もし空行か、コメントだったらスルー
			if (line.empty() || line.rfind("//", 0) == 0)continue;
			//文字が入っていればチェックをしてループを抜ける
			std::stringstream ss(line);
			std::string key, eq;
			if (ss >> key >> eq)
			{
				if (key == "ID") { ss >> id; }
				else if (key == "POS") { ss >> pos.x >> pos.y >> pos.z; }
				else if (key == "ROT") { ss >> rot.x >> rot.y >> rot.z; }
				else if (key == "SCA")
				{
					ss >> sca.x >> sca.y >> sca.z;
					new StageObject(pos, rot, sca, id);
					break;
				}
			}
		}
	}
}

//ToDo :パラメーターローダー追加
//オブジェクトの数を取得
//オブジェクトの数分繰り返し
//取得したポジション、回転、スケールと、for分の値を引数にオブジェクトを生成
