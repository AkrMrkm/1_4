/**
* @file test.h
* @brief 自動テストヘッダー
* @author 村上輝
* @date 2023/10/19/11:30
* @details  課題1_3「双方向リストのテンプレート化」\n
*			テストフィクスチャクラスの実装\n
*			そのまま使い回しです。
*/
#pragma once

#include "../DoubleList1_4/doublyLinkedList.h"
#include "../DoubleList1_4/recordData.h"

namespace auto_Test
{
	//! グローバルの成績データ(10個)
	const RecordData g_data[10]
	{
		{0,"a"},
		{1,"b"},
		{2,"c"},
		{3,"d"},
		{4,"e"},
		{5,"f"},
		{6,"g"},
		{7,"h"},
		{8,"i"},
		{9,"j"},
	};

	/**
	* @brief テストフィクスチャクラス
	* @details データが空のリスト
	*/
	class EmptyListTest : public ::testing::Test
	{
	protected:
		//! リストのポインタ
		DoublyLinkedList<RecordData>* m_List;

		/**
		* @brief 初期化
		*/
		virtual void SetUp()
		{
			m_List = new DoublyLinkedList<RecordData>();
		}

		/**
		* @brief 後処理
		*/
		virtual void TearDown()
		{
			delete m_List;
		}
	};

	/**
	* @brief データがひとつ格納されたリスト
	* @details スコアが0のデータが格納されています
	*/
	class OneDataListTest : public EmptyListTest
	{
	protected:
		/**
		* @brief 初期化
		* @details スコアが0のデータを格納
		*/
		void SetUp() override
		{
			m_List = new DoublyLinkedList<RecordData>();
			m_List->PushBack(g_data[0]);
		}
	};

	/**
	* @brief データが5つ格納されたリスト
	* @details スコアが01234の順でデータが格納されています
	*/
	class FiveDataListTest : public EmptyListTest
	{
	protected:
		/**
		* @brief 初期化
		* @details スコアが0~4のデータを5つ格納
		*/
		void SetUp() override
		{
			m_List = new DoublyLinkedList<RecordData>();
			m_List->PushBack(g_data[0]);
			m_List->PushBack(g_data[1]);
			m_List->PushBack(g_data[2]);
			m_List->PushBack(g_data[3]);
			m_List->PushBack(g_data[4]);
		}
	};


	/**
	* @brief データが空のリストが別で2つあるクラス
	*/
	class TwoEmptyListTest : public EmptyListTest
	{
	protected:
		//! リスト2のポインタ
		DoublyLinkedList<RecordData>* m_List_2;

		/**
		* @brief 初期化
		*/
		void SetUp() override
		{
			m_List = new DoublyLinkedList<RecordData>();
			m_List_2 = new DoublyLinkedList<RecordData>();
		}

		/**
		* @brief 後処理
		*/
		void TearDown() override
		{
			delete m_List;
			delete m_List_2;
		}
	};

}