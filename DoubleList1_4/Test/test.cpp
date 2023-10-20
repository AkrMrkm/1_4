/**
* @file		test.cpp
* @brief	自動テストcpp
* @author	村上輝
* @date		2023/10/20/12:00
* @details  課題1_4「クイックソート」
*/

#include "pch.h"
#include "test.h"

using namespace auto_test;

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== クイックソート ===================================

		/**********************************************************************************//**
			@brief		要素を持たないリストにソートを実行した時の挙動
			@details	ID:リスト-0\n
						エラー含めて、何も起こらなければ成功\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_Empty)
		{
			// 空のリストを作成
			DoublyLinkedList<RecordData> list;

			/* 昇順 */
			{
				DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
				DoublyLinkedList<RecordData>::Iterator endIt = list.end();

				auto cmp = [](RecordData a, RecordData b) { return a < b; };

				list.QuickSort(beginIt, endIt, cmp);

				EXPECT_EQ(0, list.GetDataNum());
			}

			/* 降順 */
			{
				DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
				DoublyLinkedList<RecordData>::Iterator endIt = list.end();

				auto cmp = [](RecordData a, RecordData b) { return a > b; };

				list.QuickSort(beginIt, endIt, cmp);

				EXPECT_EQ(0, list.GetDataNum());
			}
		}

		/**********************************************************************************//**
			@brief		要素を1つだけ持つリストにソートを実行した時の挙動
			@details	ID:リスト-1\n
						エラー含めて、何も起こらなければ成功\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_OneData)
		{
			// ひとつのデータを格納したリスト
			DoublyLinkedList<RecordData> list;
			list.PushBack({1,"a"});

			/* 昇順 */
			{
				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					RecordData data = *it;
					EXPECT_EQ(1, data.m_score);
				}
			}

			/* 降順 */
			{
				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					RecordData data = *it;
					EXPECT_EQ(1, data.m_score);
				}
			}
		}

		/**********************************************************************************//**
			@brief		2つ以上要素を持つリストにソートを実行した時の挙動
			@details	ID:リスト-2\n
						要素が指定したキーに準じて指定した順に並ぶ\n
						先頭から順にイテレータで確認し、ノードの差し替えが正常に行えているかチェック\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_AnyData)
		{
			/* 昇順 */
			{
				DoublyLinkedList<RecordData> list;

				// リストに重複無しのデータを0～9までの数字を10個格納する
				ListInitNoSameKey(list);

				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認(データ順が0123456789になっていれば成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(i, data.m_score);
					}
				}
			}

			/* 降順 */
			{
				DoublyLinkedList<RecordData> list;

				// リストに重複無しのデータを0～9までの数字を10個格納する
				ListInitNoSameKey(list);

				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認(データ順が9876543210になっていれば成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(9 - i, data.m_score);
					}
				}
			}
		}

		/**********************************************************************************//**
			@brief		同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動
			@details	ID:リスト-3\n
						要素がソートされて並ぶが、同じ要素の順序は保証されない\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_SameKey)
		{
			// データ確認用の整列されたデータ順の定数
			const int orderNumber[10] = { 0,1,1,2,2,3,4,4,5,8 };

			/* 昇順 */
			{
				DoublyLinkedList<RecordData> list;

				//(1105382244)の順でデータを格納します
				ListInitSameKey(list);

				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認(データ順が0112234458になっていれば成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(orderNumber[i], data.m_score);
					}
				}
			}

			/* 降順 */
			{
				DoublyLinkedList<RecordData> list;

				//(1105382244)の順でデータを格納します
				ListInitSameKey(list);

				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認(データ順が8544322110になっていれば成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(orderNumber[9 - i], data.m_score);
					}
				}
			}
		}

		/**********************************************************************************//**
			@brief		整列済みリストにソートを実行した時の挙動
			@details	ID:リスト-4\n
						同じキーの要素の間以外の順番が変動しない\n
						重複要素なしの整列済みリストを使う\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_LineUp_Again)
		{
			/* 昇順 */
			{
				DoublyLinkedList<RecordData> list;

				// リストに(0123456789)と昇順で整列されたデータを格納する
				ListInitLinedUp(list, true);

				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認(データ順が0123456789と変わっていなければ成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(i, data.m_score);
					}
				}
			}

			/* 降順 */
			{
				DoublyLinkedList<RecordData> list;

				// リストに(9876543210)と降順で整列されたデータを格納する
				ListInitLinedUp(list, false);

				// ソート
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// データの確認(データ順が9876543210と変わっていなければ成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(9 - i, data.m_score);
					}
				}
			}
		}

		/**********************************************************************************//**
			@brief		一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動
			@details	ID:リスト-5\n
						要素がソートされて並ぶ\n
						重複要素なしの整列済みリストを使う\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_LineUp_AfterInsert)
		{
			/* 昇順 */
			{
				/* 先頭に挿入 */
				{
					DoublyLinkedList<RecordData> list;

					// リストに(0123456789)と昇順で整列されたデータを格納する
					ListInitLinedUp(list, true);

					// 先頭に{10}を挿入
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						list.Insert(it, { 10, "a"});
					}

					// ソート
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a < b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// データの確認(データ順が0,1,2,3,4,5,6,7,8,9,10となっていれば成功)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(i, data.m_score);
						}
					}
				}
				/* 先頭から3番目に挿入 */
				{
					DoublyLinkedList<RecordData> list;

					// リストに(0123456789)と昇順で整列されたデータを格納する
					ListInitLinedUp(list, true);

					// 先頭から3番目に{10}を挿入
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						++it; 
						++it;
						list.Insert(it, { 10, "a"});
					}

					// ソート
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a < b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// データの確認(データ順が0,1,2,3,4,5,6,7,8,9,10となっていれば成功)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(i, data.m_score);
						}
					}
				}
				/* 末尾に挿入 */
				{
					DoublyLinkedList<RecordData> list;

					// リストに(0123456789)と昇順で整列されたデータを格納する
					ListInitLinedUp(list, true);

					// 末尾に{10}を挿入
					{
						DoublyLinkedList<RecordData>::Iterator it = list.end();
						list.Insert(it, { 10, "a"});
					}

					// ソート
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a < b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// データの確認(データ順が0,1,2,3,4,5,6,7,8,9,10となっていれば成功)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(i, data.m_score);
						}
					}
				}
			}
			/* 降順 */
			{
				/* 先頭に挿入 */
				{
					DoublyLinkedList<RecordData> list;

					// リストに(9876543210)と降順で整列されたデータを格納する
					ListInitLinedUp(list, false);

					// 先頭に{10}を挿入
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						list.Insert(it, { 10, "a"});
					}

					// ソート
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a > b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// データの確認(データ順が10,9,8,7,6,5,4,3,2,1,0となっていれば成功)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(10 - i, data.m_score);
						}
					}
				}
				/* 先頭から3番目に挿入 */
				{
					DoublyLinkedList<RecordData> list;

					// リストに(9876543210)と降順で整列されたデータを格納する
					ListInitLinedUp(list, false);

					// 先頭から3番目に{10}を挿入
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						++it; 
						++it;
						list.Insert(it, { 10, "a"});
					}

					// ソート
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a > b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// データの確認(データ順が10,9,8,7,6,5,4,3,2,1,0となっていれば成功)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(10 - i, data.m_score);
						}
					}
				}
				/* 末尾に挿入 */
				{
					DoublyLinkedList<RecordData> list;

					// リストに(9876543210)と降順で整列されたデータを格納する
					ListInitLinedUp(list, false);

					// 末尾に{10}を挿入
					{
						DoublyLinkedList<RecordData>::Iterator it = list.end();
						list.Insert(it, { 10, "a"});
					}

					// ソート
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a > b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// データの確認(データ順が10,9,8,7,6,5,4,3,2,1,0となっていれば成功)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(10 - i, data.m_score);
						}
					}
				}
			}
		}

		/**********************************************************************************//**
			@brief		キー指定をしなかった(nullptrを渡した)時の挙動\
			@details	ID:リスト-6\n
						エラー含めて、何も起こらなければ成功\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_Null)
		{
			DoublyLinkedList<RecordData> list;

			// データを1,3,2の順で格納
			list.PushBack({ 1,"a" });
			list.PushBack({ 3,"a" });
			list.PushBack({ 2,"a" });

			/* 昇順 */
			{
				// 参照のないイテレータを渡す
				DoublyLinkedList<RecordData>::Iterator beginIt;
				DoublyLinkedList<RecordData>::Iterator endIt;

				auto cmp = [](RecordData a, RecordData b) { return a < b; };

				list.QuickSort(beginIt, endIt, cmp);

				// データの確認(データ順が1,3,2のままであれば成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					RecordData data;
					data = *(it++);
					EXPECT_EQ(1, data.m_score);
					data = *(it++);
					EXPECT_EQ(3, data.m_score);
					data = *(it++);
					EXPECT_EQ(2, data.m_score);
				}
			}

			/* 降順 */
			{
				// 参照のないイテレータを渡す
				DoublyLinkedList<RecordData>::Iterator beginIt;
				DoublyLinkedList<RecordData>::Iterator endIt;

				auto cmp = [](RecordData a, RecordData b) { return a > b; };

				list.QuickSort(beginIt, endIt, cmp);

				// データの確認(データ順が1,3,2のままであれば成功)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					RecordData data;
					data = *(it++);
					EXPECT_EQ(1, data.m_score);
					data = *(it++);
					EXPECT_EQ(3, data.m_score);
					data = *(it++);
					EXPECT_EQ(2, data.m_score);
				}
			}
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