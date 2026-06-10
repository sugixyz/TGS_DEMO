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
	/// <param name="path">参照するファイル</param>
	/// <param name="func">実行する判定処理</param>
	void SetParam(const char* path, std::function<void(const std::string& key, std::stringstream& ss)> func);
}
