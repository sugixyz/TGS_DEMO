#include "ParamLoader.h"
#include"../../SourceCode/Player.h"

void Loader::AllClassParamLoad()
{
	Player::LoadParam();
}

void Loader::SetParam(const char* path, std::function<void(const std::string& key, std::stringstream& ss)> func)
{
	std::ifstream file(path);
	//ファイルがなければスルー
	if (!file.is_open())return;

	std::string line;
	while (std::getline(file, line))
	{
		//もし空行か、コメントだったらスルー
		if (line.empty() || line.rfind("//", 0) == 0)continue;

		std::stringstream ss(line);
		std::string key, eq;
		if (ss >> key >> eq)
		{
			//クラスの独自のものを呼ぶ
			func(key, ss);
		}
	}
}
