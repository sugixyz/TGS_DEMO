#pragma once
#include<functional>
#include<string>
#include<sstream>
#include<fstream>

namespace Loader
{
	/// <summary>
	/// ///パラメータを読み込む
	/// </summary>
	void AllClassParamLoad();

	/// <summary>
	/// 共通のファイル検索関数
	/// </summary>
	/// <param name="path"></param>
	/// <param name="logic"></param>
	void SetParam(const char* path, std::function<void(const std::string& key, std::stringstream& ss)> logic);
}
