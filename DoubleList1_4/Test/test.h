/**
* @file	    test.h
* @brief    テストヘッダー
* @author   村上輝
* @date     2023/10/20/11:00
* @details  課題1_4「クイックソートの実装」\n
			自動テストで使う、リストに特定のデータを格納する初期化関数を記述しています。\n
*/

#pragma once

#include "../DoubleList1_4/doublyLinkedList.h"
#include "../DoubleList1_4/recordData.h"

namespace auto_test
{
	/**
	* @brief    重複無しのバラバラのデータが格納された状態に初期化する関数
	* @details  自動テスト用の初期化関数です。\n
	*			(4275108936)の順でデータを格納します。\n
	*/
	void ListInitNoSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 4, "a" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 7, "a" });
		list.PushBack({ 5, "a" });
		list.PushBack({ 1, "a" });
		list.PushBack({ 0, "a" });
		list.PushBack({ 8, "a" });
		list.PushBack({ 9, "a" });
		list.PushBack({ 3, "a" });
		list.PushBack({ 6, "a" });
	}

	/**
	* @brief    重複有りのバラバラのデータが格納された状態に初期化する関数
	* @details  自動テスト用の初期化関数です。\n
	*			(1105382244)の順でデータを格納します。\n
	*/
	void ListInitSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 1, "a" });
		list.PushBack({ 1, "a" });
		list.PushBack({ 0, "a" });
		list.PushBack({ 5, "a" });
		list.PushBack({ 3, "a" });
		list.PushBack({ 8, "a" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 4, "a" });
		list.PushBack({ 4, "a" });
	}


	/**
	* @brief     データを整列した状態に初期化する関数
	* @param[in] list 初期化するリスト
	* @param[in] isAscendingOrder trueならば昇順、falseならば降順で格納します。\n
	* @details   自動テスト用の初期化関数です。\n
	*			 0～9を格納します。\n
	*/
	void ListInitLinedUp(DoublyLinkedList<RecordData>& list, bool isAscendingOrder)
	{
		// リストを空にする
		{
			DoublyLinkedList<RecordData>::Iterator it = list.begin();
			auto endIt = list.end();
			for (auto it = list.begin(); it != endIt; it++)
			{
				list.Remove(it);
			}
		}

		if (isAscendingOrder)
			for (int i = 0; i < 10; i++)
			{
				list.PushBack({ i, "a" });
			}
		else
			for (int i = 9; i >= 0; i--)
			{
				list.PushBack({ i, "a" });
			}
	}
}