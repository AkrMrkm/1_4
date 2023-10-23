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
	//! 名前で昇順
	bool NameAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_name < b.m_name; };

	//! 名前で降順
	bool NameDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_name > b.m_name; };

	//! スコアで昇順
	bool ScoreAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_score < b.m_score; };

	//! スコアで降順
	bool ScoreDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_score > b.m_score; };

	/**
	* @brief    重複無しのバラバラのデータが格納された状態に初期化する関数
	* @details  自動テスト用の初期化関数です。\n
	*			(4275108936)の順でデータを格納します。\n
	*			(cadjhifegb)の順でデータを格納します。\n
	*/
	void InitListNoSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 4, "c" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 7, "d" });
		list.PushBack({ 5, "j" });
		list.PushBack({ 1, "h" });
		list.PushBack({ 0, "i" });
		list.PushBack({ 8, "f" });
		list.PushBack({ 9, "e" });
		list.PushBack({ 3, "g" });
		list.PushBack({ 6, "b" });
	}

	/**
	* @brief    重複有りのバラバラのデータが格納された状態に初期化する関数
	* @details  自動テスト用の初期化関数です。\n
	*			(1105382244)の順でデータを格納します。\n
	*			(afacbbaded)の順でデータを格納します。\n
	*/
	void InitListSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 1, "a" });
		list.PushBack({ 1, "f" });
		list.PushBack({ 0, "a" });
		list.PushBack({ 5, "c" });
		list.PushBack({ 3, "b" });
		list.PushBack({ 8, "b" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 2, "d" });
		list.PushBack({ 4, "e" });
		list.PushBack({ 4, "d" });
	}
}