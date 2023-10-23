/**
* @file test.cpp
* @brief 自動テストcpp
* @author 村上輝
* @date 2023/10/19/11:30
* @details 課題1_3「双方向リストのテンプレート化」
*			そのまま使い回しです。
*/

#include "pch.h"
#include "basicTest.h"

using namespace auto_Test;

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== データ数の取得 ===================================
		typedef EmptyListTest GetDataNumTestEmpty;
		typedef OneDataListTest GetDataNumTestOneData;

		/**********************************************************************************//**
			@brief		リストが空である場合のデータ数の取得テスト
			@details	ID:リスト-0\n
						データ数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
						データ数が空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_WhenEmpty)
		{
			EXPECT_EQ(0, m_List->GetDataNum()) << "リストが空である場合のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-1\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入を行った際の戻り値を確認しています。\n
						データ数が1増えていれば成功です。\n
						データ数が空のリストを使用\n
		 *//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_InsertEnd)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			ASSERT_TRUE(m_List->Insert(it, g_data[0])); // データをひとつ挿入

			EXPECT_EQ(1, m_List->GetDataNum()) << "リスト末尾への挿入を行った際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
			@details	ID:リスト-2\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		//*//***********************************************************************************/
		TEST(GetDataNumTest, Test_GetDataNum_InsertEnd_Failed)
		{
			// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-3\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が1であれば成功です。\n
						データ数が空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_Insert)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			ASSERT_TRUE(m_List->Insert(it, g_data[0])); // データをひとつ挿入

			EXPECT_EQ(1, m_List->GetDataNum()) << "データの挿入を行った際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		データの挿入に失敗した際のデータ数の取得テスト
			@details	ID:リスト-4\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, Test_GetDataNum_Insert_Failed)
		{
			// 挿入失敗はメモリ確保失敗時のためここではスキップ
		}

		/**********************************************************************************//**
			@brief		データの削除を行った際のデータ数の取得テスト
			@details	ID:リスト-5\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						最初にデータをひとつ挿入して、削除を行っています。\n
						データ数が0であれば成功です。\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestOneData, Test_GetDataNum_Remove)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			m_List->Remove(it);

			EXPECT_EQ(0, m_List->GetDataNum()) << m_List->GetDataNum() << "データの削除を行った際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		データの削除に失敗した際のデータ数の取得テスト
			@details	ID:リスト-6\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						最初にデータをひとつ挿入して、削除を行っています。\n
						データ数が1であれば成功です。\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestOneData, Test_GetDataNum_Remove_Failed)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			m_List->Remove(it);

			EXPECT_EQ(1, m_List->GetDataNum()) << m_List->GetDataNum() << "データの削除に失敗した際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		リストが空である場合にデータの削除をした際のデータ数の取得テスト
			@details	ID:リスト-7\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						データ数がマイナスでなければ成功です。\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_Remove_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			ASSERT_FALSE(m_List->Remove(it));

			EXPECT_EQ(0, m_List->GetDataNum());
		}

		// 8はマニュアルテスト

		//=================================== データの挿入 ===================================
		typedef FiveDataListTest InsertTestFiveDataList;
		typedef TwoEmptyListTest InsertTestTwoEmptyList;

		/**********************************************************************************//**
			@brief		リストが空である場合に、挿入した際の挙動
			@details	ID:リスト-9\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						先頭イテレータ、末尾イテレータを引数で渡した場合について、個別に挙動をチェックすること\n
						2つの空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(InsertTestTwoEmptyList, Test_Insert_Empty)
		{
			// 先頭に挿入
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				EXPECT_TRUE(m_List->Insert(it, g_data[0]));
				EXPECT_EQ(1, m_List->GetDataNum());
			}

			// 末尾に挿入
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List_2->end();
				EXPECT_TRUE(m_List_2->Insert(it, g_data[0]));
				EXPECT_EQ(1, m_List_2->GetDataNum());
			}
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動テスト
			@details	ID:リスト-10\n
						先頭に要素が挿入され、元々先頭だった要素が２番目になれば成功です。\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_Begin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			// 先頭に5を挿入
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			//先頭だった要素が二番目になっていたら成功(順番が501234になっていたら成功)
			it = m_List->begin();
			RecordData itData = *it;
			EXPECT_EQ(5, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動テスト
			@details	ID:リスト-11\n
						イテレータの指す位置に要素が挿入される\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_End)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			// 末尾に5を挿入
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			// (順番が012345になっていたら成功)
			it = m_List->begin();
			RecordData itData = *it;
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(5, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動テスト
			@details	ID:リスト-12\n
						TRUEで成功\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_Other)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			++it;
			++it;
			++it;

			// 先頭から4番目に5を挿入
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			// (順番が012534になっていたら成功)
			it = m_List->begin();
			RecordData itData = *it;
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(5, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIteratorを指定して挿入をした際の挙動テスト
			@details	ID:リスト-13\n
						TRUEで成功\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか。\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_Const)
		{
			// 元のデータのスコア順は01234
			// 先頭に挿入
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();

				// 先頭に５を挿入
				m_List->Insert(it, g_data[5]);

				// 順番が501234になってたら成功
				it = m_List->begin();
				RecordData itData = *it;
				EXPECT_EQ(5, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(0, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// 3番目に挿入
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				++it;
				// 先頭から3番目に６を挿入
				m_List->Insert(it, g_data[6]);
				// 順番が5061234になってたらTRUE
				it = m_List->begin();
				RecordData itData = *it;
				EXPECT_EQ(5, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(0, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(6, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// 末尾に挿入
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				// 末尾に７を挿入
				m_List->Insert(it, g_data[7]);
				// 順番が5061234になってたらTRUE
				it = m_List->begin();
				RecordData itData = *it;
				EXPECT_EQ(5, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(0, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(6, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(7, itData.m_score);
			}
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡して、挿入した場合の挙動テスト
			@details	ID:リスト-14\n
						リストの参照が無いイテレータを渡した際の挙動など\n
						何も起こらなければ成功\n
						2つの空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(InsertTestTwoEmptyList, Test_Insert_Unknown)
		{
			// 二つの空のリストに要素をひとつ挿入しておく
			m_List->PushBack(g_data[0]);
			m_List_2->PushBack(g_data[0]);

			// リストの参照が無いイテレータを挿入したとき
			DoublyLinkedList<RecordData>::Iterator it;
			EXPECT_FALSE(m_List->Insert(it, g_data[2]));
			//データ数が変わっていなければ成功
			EXPECT_EQ(1, (m_List->GetDataNum()));

			// リスト２のイテレータをリスト１に渡して挿入したとき(別のリストを参照したとき)
			it = m_List_2->begin();
			EXPECT_FALSE(m_List->Insert(it, g_data[2]));
			//データ数が変わっていなければ成功
			EXPECT_EQ(1, (m_List->GetDataNum()));
		}

		// 15はマニュアルテスト

		//=================================== データの削除 ===================================
		typedef EmptyListTest RemoveTestEmpty;
		typedef FiveDataListTest RemoveTestFiveData;

		/**********************************************************************************//**
			@brief		リストが空である場合に、削除を行った際の挙動
			@details	ID:リスト-16\n
						FALSEで成功\n
						先頭イテレータ、末尾イテレータを引数で渡した場合について、個別に挙動をチェックすること\n
		*//***********************************************************************************/
		TEST_F(RemoveTestEmpty, Test_Remove_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			EXPECT_FALSE(m_List->Remove(it));

			it = m_List->end();
			EXPECT_FALSE(m_List->Remove(it));
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
			@details	ID:リスト-17\n
						先頭要素の削除\n
						TRUEで成功\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_Begin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_TRUE(m_List->Remove(it));

			// 先頭要素がなくなっていれば成功
			// 元のデータ順が01234なので、1234になっていれば成功
			it = m_List->begin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(2, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(3, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(4, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
			@details	ID:リスト-18\n
						要素数が変わらなければfalseで成功\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_End)
		{
			const int oldNum = m_List->GetDataNum();

			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_FALSE(m_List->Remove(it));

			//要素数が変わっていなければ成功
			EXPECT_FALSE((oldNum != m_List->GetDataNum())) << oldNum << m_List->GetDataNum();
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
			@details	ID:リスト-19\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか\n
						TRUEで成功\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, TestRemoveOther)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			// 2番目を削除
			m_List->Remove(++it);

			it = m_List->begin();
			RecordData itData = *it;

			// 元のデータ順が01234なので、0234になっていれば成功
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIteratorを指定して削除を行った際の挙動
			@details	ID:リスト-20\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか\n
						TRUEで成功\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_Other_Const)
		{
			// 元のデータのスコア順は01234
			// 先頭を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(it);

				it = m_List->begin();
				RecordData itData = *it;

				//順番が1234になっていれば成功
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// 先頭から2番目を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(++it);

				it = m_List->begin();
				RecordData itData = *it;

				//順番が134になっていれば成功
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// 末尾イテレータを渡して削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);

				it = m_List->begin();
				RecordData itData = *it;

				//順番が134で変わっていなければ成功
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}
		}
		/**********************************************************************************//**
			@brief		不正なイテレータを渡して、削除した場合の挙動
			@details	ID:リスト-21\n
						リストの参照がないイテレータ、別リストの要素を指すイテレータを渡した際の挙動など\n
						何も起こらない\n
						FALSEで成功\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_Unknown)
		{
			const int oldNum = m_List->GetDataNum();

			// 参照の無いイテレータを渡したとき
			{
				DoublyLinkedList<RecordData>::Iterator it;
				m_List->Remove(it);
				//データの総数が変わっていなければ成功
				EXPECT_EQ(oldNum, m_List->GetDataNum());
			}

			// 別のリストのイテレータを渡したとき
			{
				DoublyLinkedList<RecordData> list2;
				list2.PushBack(g_data[0]);
				DoublyLinkedList<RecordData>::Iterator it = list2.begin();
				m_List->Remove(it);
				//データの総数が変わっていなければ成功
				EXPECT_EQ(oldNum, m_List->GetDataNum());
			}
		}

		// 22はマニュアルテスト


		//=================================== 先頭イテレータの取得 ===================================
		typedef EmptyListTest beginTestEmpty;
		typedef OneDataListTest beginTestOneData;
		typedef FiveDataListTest beginTestFiveData;

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-23\n
						ダミーノードを指すイテレータが返る\n
						データが空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(beginTestEmpty, Test_begin_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator endIt = m_List->end();

			// 先頭イテレータと末尾イテレータが等しければ成功
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-24\n
						先頭要素を指すイテレータが返る\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(beginTestOneData, Test_begin_One)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-25\n
						先頭要素を指すイテレータが返る\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(beginTestFiveData, Test_begin_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-26\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(beginTestOneData, Test_begin_AfterInsert)
		{
			// 元から入っているデータを確認
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				RecordData itData = *it;
				//0が入っていれば成功
				EXPECT_EQ(0, (itData.m_score));
			}

			//先頭に挿入した後の確認
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->begin();
				RecordData itData = *it;
				//先頭に1が入っていればOK
				EXPECT_EQ(1, (itData.m_score));
			}

			//先頭から2番目に挿入した後の確認
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->begin();
				RecordData itData = *it;
				//先頭に1がそのまま入っていればOK
				EXPECT_EQ(1, (itData.m_score));
			}

			//末尾に挿入した後の確認
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->begin();
				RecordData itData = *it;
				//先頭に1がそのまま入っていればOK
				EXPECT_EQ(1, (itData.m_score));
			}
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-27\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾の要素の削除を行った場合の各ケースについてチェックすること\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(beginTestFiveData, Test_begin_AfterRemove)
		{
			// 元のデータのスコア順は01234
			// 先頭の要素を削除
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 先頭の０が消えて、1が入っていればOK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// 先頭から2番目の要素を削除
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				++it;
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1が入っていればOK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// 末尾の要素を削除
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1が入っていればOK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}
		}

		// 28はマニュアルテスト


		//=================================== 先頭コンストイテレータの取得 ===================================
		typedef EmptyListTest GetConstBeginTestEmpty;
		typedef OneDataListTest GetConstBeginTestOneData;
		typedef FiveDataListTest GetConstBeginTestFiveData;

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-29\n
						ダミーノードを指すイテレータが返る\n
						データが空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestEmpty, Test_GetConstBegin_Empty)
		{
			DoublyLinkedList<RecordData>::ConstIterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::ConstIterator endIt = m_List->end();

			// 先頭イテレータと末尾イテレータが等しければ成功
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-30\n
						先頭要素を指すイテレータが返る\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestOneData, Test_GetConstBegin_One)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-31\n
						先頭要素を指すイテレータが返る\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestFiveData, Test_GetConstBegin_Any)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-32\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestOneData, Test_GetConstBegin_AfterInsert)
		{
			// 元から入っているデータを確認
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				RecordData itData = *it;
				//0が入っていれば成功
				EXPECT_EQ(0, (itData.m_score));
			}

			//先頭に挿入した後の確認
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->begin();
				RecordData itData = *it;
				//先頭に1が入っていればOK
				EXPECT_EQ(1, (itData.m_score));
			}

			//先頭から2番目に挿入した後の確認
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->begin();
				RecordData itData = *it;
				//先頭に1がそのまま入っていればOK
				EXPECT_EQ(1, (itData.m_score));
			}

			//末尾に挿入した後の確認
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->begin();
				RecordData itData = *it;
				//先頭に1がそのまま入っていればOK
				EXPECT_EQ(1, (itData.m_score));
			}
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-33\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestFiveData, Test_GetConstBegin_AfterRemove)
		{
			// 元のデータのスコア順は01234
			// 先頭の要素を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 先頭の０が消えて、1が入っていればOK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// 先頭から2番目の要素を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1が入っていればOK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// 末尾の要素を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1が入っていればOK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}
		}

		// 34はマニュアルテスト


		//=================================== 末尾イテレータの取得 ===================================
		typedef EmptyListTest endTestEmpty;
		typedef OneDataListTest endTestOneData;
		typedef FiveDataListTest endTestFiveData;

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-35\n
						ダミーノードを指すイテレータが返る\n
						データが空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, Test_end_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator endIt = m_List->end();

			// 先頭イテレータと末尾イテレータが等しければ成功
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-36\n
						末尾要素を指すイテレータが返る\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(endTestOneData, Test_end_One)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			// 末尾イテレータの前の要素が最初に入れた値であったら成功
			RecordData itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-37\n
						末尾要素を指すイテレータが返る\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(endTestFiveData, Test_end_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			// 元のデータのスコア順は01234なので
			// 末尾イテレータの前の要素が4であったら成功
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-38\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(endTestOneData, Test_end_AfterInsert)
		{
			// 元から入っているデータを確認
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, (itData.m_score)); // 末尾の前要素データのスコアが0だったら成功
			}

			// 先頭に挿入
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // 末尾の前要素データのスコアが0だったら成功
			}

			// 2番目に挿入
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // 末尾の前要素データのスコアが0のままだったら成功
			}

			// 末尾に挿入
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // 末尾の前要素データのスコアが3だったら成功
			}
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-39\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に削除を行った場合の各ケースについてチェックすること\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(endTestFiveData, Test_end_AfterRemove)
		{
			// 元のデータがのスコア順は01234
			// 先頭の要素を削除
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
			}

			// 先頭から2番目の要素を削除
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Remove(++it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
			}

			// 末尾イテレータの要素を削除
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
				// 末尾イテレータはダミーノードなので変わらない
			}

			// 末尾イテレータのひとつ前の要素を削除
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Remove(--it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // 末尾の前要素データのスコアが3だったら成功
			}
		}

		//40はマニュアルテスト


		//=================================== 末尾コンストイテレータの取得 ===================================
		typedef EmptyListTest GetConstEndTestEmpty;
		typedef OneDataListTest GetConstEndTestOneData;
		typedef FiveDataListTest GetConstEndTestFiveData;

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-41\n
						ダミーノードを指すイテレータが返る\n
						データが空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestEmpty, Test_GetConstEnd_Empty)
		{
			DoublyLinkedList<RecordData>::ConstIterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::ConstIterator endIt = m_List->end();

			// 先頭イテレータと末尾イテレータが等しければ成功
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-42\n
						末尾要素を指すイテレータが返る\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestOneData, Test_GetConstEnd_One)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();

			// 末尾イテレータの前の要素が最初に入れた値であったら成功
			RecordData itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-43\n
						末尾要素を指すイテレータが返る\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestFiveData, Test_GetConstEnd_Any)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();

			// 元のデータのスコア順は01234なので
			// 末尾イテレータの前の要素が4であったら成功
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-44\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestOneData, Test_GetConstEnd_AfterInsert)
		{
			// 元から入っているデータを確認
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, (itData.m_score)); // 末尾の前要素データのスコアが0だったら成功
			}

			// 先頭に挿入
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // 末尾の前要素データのスコアが0だったら成功
			}

			// 2番目に挿入
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // 末尾の前要素データのスコアが0のままだったら成功
			}

			// 末尾に挿入
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // 末尾の前要素データのスコアが3だったら成功
			}
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-45\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestFiveData, Test_GetConstEnd_AfterRemove)
		{
			// 元のデータがのスコア順は01234
			// 先頭の要素を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
			}

			// 先頭から2番目の要素を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(++it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
			}

			// 末尾イテレータの要素を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
				// 末尾イテレータはダミーノードなので変わらない
			}

			// 末尾イテレータのひとつ前の要素を削除
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(--it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // 末尾の前要素データのスコアが3だったら成功
			}
		}

		//46はマニュアルテスト
	}

	//=====================================================================================================
	//=====================================================================================================
	//=====================================================================================================

	namespace chapter2
	{
		//===================================イテレータの指す要素の取得 ===================================
		typedef EmptyListTest GetItTestEmpty;
		typedef OneDataListTest GetItTestOneData;

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動
			@details	ID:リスト-0\n
						Assert発生\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetItTestEmpty, Test_GetIt_NoReference)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(*it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		Iteratorから取得した要素に対して、値の代入が行えるかをチェック
			@details	ID:リスト-1\n
						代入後に再度呼び出し、値が変更されていることを確認\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetItTestOneData, Test_GetIt_Assign)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			*it = g_data[1]; // 別のデータを代入
			RecordData itData = *it;

			// １が入っていれば成功
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
			@details	ID:リスト-3\n
						Assert発生\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetItTestEmpty, Test_GetIt_EmptyBegin)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_DEATH(*it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動
			@details	ID:リスト-4\n
						Assert発生\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(GetItTestOneData, Test_GetIt_EmptyEnd)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_DEATH(*it, ".*"); // ダミーノードを指すのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		//===================================イテレータをリストの末尾に向かってひとつ進める===================================
		typedef EmptyListTest IncrementTestEmpty;
		typedef OneDataListTest IncrementTestOneData;
		typedef FiveDataListTest IncrementTestFiveData;

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動
			@details	ID:リスト-5\n
						Assert発生\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(IncrementTestEmpty, Test_Increment_NoReference)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(++it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
			@details	ID:リスト-6\n
						Assert発生\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(IncrementTestEmpty, Test_Increment_TestEmptyBegin)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_DEATH(++it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動
			@details	ID:リスト-7\n
						Assert発生\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(IncrementTestOneData, Test_Increment_EndIt)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_DEATH(++it, ".*"); // ダミーノードを指すのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
			@details	ID:リスト-8\n
						次の要素を指す\n
						リストの先頭から末尾まで呼び出しを行い、期待されている要素が格納されているかを確認\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(IncrementTestFiveData, Test_Increment_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			RecordData itData = *it;

			// 01234であれば成功
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
			@details	ID:リスト-9\n
						次の要素を指す\n
						インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(IncrementTestFiveData, Test_Increment_PrefIncrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			RecordData itData = *it;

			// 01234であれば成功
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
			@details	ID:リスト-10\n
						次の要素を指す\n
						インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(IncrementTestFiveData, Test_Increment_BackIncrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			RecordData itData = *it;

			// 00123であれば成功
			EXPECT_EQ(0, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(0, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(1, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(2, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(3, itData.m_score);
		}


		//===================================イテレータをリストの先頭に向かってひとつ進める===================================
		typedef EmptyListTest DecrementTestEmpty;
		typedef OneDataListTest DecrementTestOneData;
		typedef FiveDataListTest DecrementTestFiveData;

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動
			@details	ID:リスト-11\n
						Assert発生\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(DecrementTestEmpty, Test_Decrement_NoReference)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(--it, ".*"); // リストの参照がないのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		リストが空の際の、末尾イテレータに対して呼び出した際の挙動
			@details	ID:リスト-12\n
						Assert発生\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(DecrementTestEmpty, Test_Decrement_EmptyEnd)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_DEATH(--it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		先頭イテレータに対して呼び出した際の挙動
			@details	ID:リスト-13\n
						Assert発生\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(DecrementTestOneData, Test_Decrement_BeginIt)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_DEATH(--it, ".*"); // ダミーノードを指すのでアサートが発生してプログラムが異常終了することを確認
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
			@details	ID:リスト-14\n
						前の要素を指す\n
						リストの末尾から先頭まで呼び出しを行い、期待されている要素が格納されているかを確認\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(DecrementTestFiveData, Test_Decrement_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();
			RecordData itData = *(--it);

			// 43210であれば成功
			EXPECT_EQ(4, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		前置デクリメント行った際の挙動( --演算子オーバーロードで実装した場合 )
			@details	ID:リスト-15\n
						次の要素を指す\n
						デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(DecrementTestFiveData, Test_Decrement_PrefDecrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();
			RecordData itData = *(--it);

			// 43210であれば成功
			EXPECT_EQ(4, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
			@details	ID:リスト-16\n
						次の要素を指す\n
						デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(DecrementTestFiveData, Test_Decrement_BackDecrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();
			RecordData itData = *(--it);

			// 44321であれば成功
			EXPECT_EQ(4, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(4, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(3, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(2, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(1, itData.m_score);
		}

		//17はマニュアルテスト

		//===================================イテレータのコピーを行う===================================
		typedef OneDataListTest CopyTestOneData;
		/**********************************************************************************//**
			@brief		イテレータのコピーを行う
			@details	ID:リスト-18\n
						コピーコンストラクト後の値がコピー元と等しいことをチェック\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(CopyTestOneData, Test_Copy_Equal)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = it;

			RecordData itData = *it;
			RecordData itData2 = *it2;

			EXPECT_TRUE(it == it2);
			EXPECT_TRUE(itData.m_score == itData2.m_score);
		}

		//19はマニュアルテスト

		//===================================イテレータの代入を行う===================================
		typedef FiveDataListTest AssignTestFiveData;
		/**********************************************************************************//**
			@brief		イテレータの代入を行う
			@details	ID:リスト-20\n
						代入後の値がコピー元と等しいことをチェック\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(AssignTestFiveData, Test_Assign_Equal)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();

			++it2;
			it2 = it;

			RecordData itData = *it;
			RecordData itData2 = *it2;

			EXPECT_TRUE(it == it2);
			EXPECT_TRUE(itData.m_score == itData2.m_score);
		}


		//===================================ふたつのイテレータが同一のものであるか比較===================================
		typedef EmptyListTest    EqualTestEmpty;
		typedef OneDataListTest  EqualTestOneData;
		typedef FiveDataListTest EqualTestFiveData;

		/**********************************************************************************//**
			@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
			@details	ID:リスト-21\n
						TRUEで成功\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(EqualTestEmpty, Test_Equal_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->end();

			EXPECT_TRUE(it == it2);
		}

		/**********************************************************************************//**
			@brief		同一のイテレータを比較した際の挙動
			@details	ID:リスト-22\n
						TRUEで成功\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(EqualTestOneData, Test_Equal_Same)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();

			EXPECT_TRUE(it == it2);
		}

		/**********************************************************************************//**
			@brief		異なるイテレータを比較した際の挙動
			@details	ID:リスト-23\n
						FALSEで成功\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(EqualTestFiveData, Test_Equal_Diff)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();
			++it2;

			EXPECT_FALSE(it == it2);
		}


		//===================================ふたつのイテレータが異なるものであるか比較===================================
		typedef EmptyListTest    NotEqualTestEmpty;
		typedef OneDataListTest  NotEqualTestOneData;
		typedef FiveDataListTest NotEqualTestFiveData;

		/**********************************************************************************//**
			@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
			@details	ID:リスト-24\n
						空のリストを使用\n
		*//***********************************************************************************/
		TEST_F(NotEqualTestEmpty, Test_NotEqual_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->end();

			EXPECT_FALSE(it != it2);
		}

		/**********************************************************************************//**
			@brief		同一のイテレータを比較した際の挙動
			@details	ID:リスト-25\n
						データがひとつ格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(NotEqualTestOneData, Test_NotEqual)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();

			EXPECT_FALSE(it != it2);
		}

		/**********************************************************************************//**
			@brief		異なるイテレータを比較した際の挙動
			@details	ID:リスト-26\n
						5つのデータが格納されたリストを使用\n
		*//***********************************************************************************/
		TEST_F(NotEqualTestFiveData, Test_NotEqual_Diff)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();
			it2++;

			EXPECT_TRUE(it != it2);
		}
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}