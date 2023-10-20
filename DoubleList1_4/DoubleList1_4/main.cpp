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

	{
		// 昇順ソート
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
			DoublyLinkedList<RecordData>::Iterator endIt = list.end();

			auto cmp = [](RecordData a, RecordData b) { return a < b; }; // 昇順

			list.QuickSort(beginIt, endIt, cmp);
		}

		std::cout << "[昇順]" << std::endl;

		// リストを格納した順で表示
		for (const RecordData& data : list)
		{
			std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
		}
	}

	std::cout << "\n もう一度キーを押すと降順でソートします。" << std::endl;
	getchar();

	{
		// 降順ソート
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
			DoublyLinkedList<RecordData>::Iterator endIt = list.end();

			auto cmp = [](RecordData a, RecordData b) { return a > b; }; // 降順

			list.QuickSort(beginIt, endIt, cmp);
		}

		std::cout << "[降順]" << std::endl;

		// リストを格納した順で表示
		for (const RecordData& data : list)
		{
			std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
		}
	}

	getchar();

	return 0;
}