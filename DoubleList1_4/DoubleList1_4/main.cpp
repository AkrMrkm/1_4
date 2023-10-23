/**
* @file		main.cpp
* @brief	双方向リストクラス
* @author	村上輝
* @date		2023/10/20/11:00
* @details  課題1_4「クイックソート」
*/

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"
#include "recordData.h"

// 名前で昇順
bool NameAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_name < b.m_name; };

// 名前で降順
bool NameDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_name > b.m_name; };

// スコアで昇順
bool ScoreAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_score < b.m_score; };

// スコアで降順
bool ScoreDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_score > b.m_score; };

int main()
{
	//ファイル読み込み
	std::ifstream inputFile("Scores.txt");

	// ファイルを開けなかったら終了
	if (!inputFile.is_open())
	{
		std::cerr << "ファイルを開けません。" << std::endl;
		getchar();
		return 0;
	}

	DoublyLinkedList<RecordData> list;

	// ファイルから読み込んだ値を格納する変数
	int score;
	std::string name;

	// ファイルからデータを読み込んでリストに追加
	while (inputFile >> score >> name)
	{
		RecordData data = { score,name };
		list.PushBack(data);
	}

	// ファイルを閉じる
	inputFile.close();

	// ソート
	{
		list.QuickSort(ScoreAscendingOrder);
		//list.QuickSort(DescendingOrder);
	}

	// リストを表示
	for (const RecordData& data : list)
	{
		std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
	}

	getchar();

	return 0;
}
