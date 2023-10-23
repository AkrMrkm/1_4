/**
* @file manualTest.h
* @brief 手動テストcpp
* @author 村上輝
* @date 2023/10/19/11:30
* @details 課題1_3「双方向リストのテンプレート化」\n
*/

#include "pch.h"
#include "manualTest.h"
#include "../DoubleList1_4/doublyLinkedList.h"
#include "../DoubleList1_4/recordData.h"

/**********************************************************************************//**
	@brief		データ数の取得機能について、constのメソッドであるかのテスト
	@details	ID:リスト-8(手動)\n
				データ数の取得機能のテストです。\n
				constのメソッドであるかを確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(ListManualTest, Test_GetDataNum_WhenConst)
{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}


/**********************************************************************************//**
	@brief		リスト末尾のデータ追加について、非constが保障されているかのテスト
	@details	ID:リスト-15(手動)\n
				リスト末尾のデータ追加テストです。\n
				非constが保障されているかを確認しています。\n
				有効にしてコンパイルエラーになれば成功です。\n
				TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Insert_WhenConst)
{
#if defined TT_TEST_INSERT_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.begin();
	RecordData data{ 1, "a" };
	list.Insert(it, data);//ここでエラー
#endif //TT_TEST_INSERT_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		非constのメソッドであるか
	@details	ID:リスト-22\

				コンパイルエラーで成功\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Remove_WhenConst)
{
#if defined TT_TEST_REMOVE_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.begin();
	list.Remove(it); // ここでエラー
#endif //TT_TEST_REMOVE_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	@details	ID:リスト-28\n
				コンパイルエラーで成功\n
*//***********************************************************************************/
TEST(ListManualTest, Testbegin_Const)
{
#if defined TT_TEST_BEGIN_WHEN_NO_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::Iterator it = list.begin();// ここでエラー
#endif //TT_TEST_BEGIN_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのメソッドであるか
	@details	ID:リスト-34\n
				コンパイルエラーが通れば成功\n
*//***********************************************************************************/
TEST(ListManualTest, Test_begin_Const)
{
#if defined TT_TEST_BEGIN_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.begin();
#endif //TT_TEST_BEGIN_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	@details	ID:リスト-40\n
				コンパイルエラーで成功\n
*//***********************************************************************************/
TEST(ListManualTest, Test_end_Const)
{
#if defined TT_TEST_END_WHEN_NO_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::Iterator it = list.end();// ここでエラー
#endif //TT_TEST_END_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのメソッドであるか
	@details	ID:リスト-46\n
				コンパイルが通れば成功\n
*//***********************************************************************************/
TEST(ListManualTest, Testend_Const)
{
#if defined TT_TEST_END_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.end();
#endif //TT_TEST_END_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		ConstIteratorから取得した要素に対して、値の代入が行えるかをチェック
	@details	ID:リスト-2\n
				コンパイルエラーになることをチェック。自動テスト化しなくてよい。\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Assign_ConstIt)
{
#if defined TT_TEST_ITE_ASSIGN_CONST
	DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.begin();
	RecordData data{ 1, "a" };
	*it = data;
#endif //TT_TEST_ITE_ASSIGN_CONST
	SUCCEED();
}



//===================================イテレータのコピーを行う===================================

/**********************************************************************************//**
	@brief		ConstIteratorから、Iteratorのコピーが作成されないかをチェック
	@details	ID:リスト-17\n
				コンパイルエラーになることを確認する。自動テスト化しなくてよい。\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Copy_Const)
{
#if defined TT_TEST_COPY_WHEN_CONST
	DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator cit = list.begin();
	DoublyLinkedList<RecordData>::Iterator cit = cit;
#endif //TT_TEST_COPY_WHEN_CONST
	SUCCEED();
}




//===================================イテレータの代入を行う===================================

/**********************************************************************************//**
	@brief		IteratorにConstIteratorを代入できない事をチェック
	@details	ID:リスト-19\n
				コンパイルエラーになることを確認する。自動テスト化しなくてよい。\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Assign_Const)
{
#if defined TT_TEST_ASSIGN_WHEN_CONST
	DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator cit = list.begin();
	DoublyLinkedList<RecordData>::Iterator it = list.begin();
	it = cit; // ここでエラー
#endif //TT_TEST_ASSIGN_WHEN_CONST
	SUCCEED();
}

//====================================ソートテスト===============================================

/**********************************************************************************//**
	@brief		型などが不適切なキー指定が引数で渡された時の挙動
	@details	ID:リスト-7(手動)\n 
				コンパイルエラーとなれば成功\n
*//***********************************************************************************/

// 不適切なキー
bool IntAscendingOrder(const int& a, const int& b) { return a < b; };

// 名前で昇順
bool NameAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_name < b.m_name; };

// 名前で降順
bool NameDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_name > b.m_name; };

// スコアで昇順
bool ScoreAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_score < b.m_score; };

// スコアで降順
bool ScoreDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_score > b.m_score; };


TEST(ListManualTest, Test_Unknown)
{
#if defined TT_TEST_UNKNOWN

	DoublyLinkedList<RecordData> list;

	list.QuickSort(IntAscendingOrder);

#endif //TT_TEST_UNKNOWN
	SUCCEED();
}

/**********************************************************************************//**
	@brief		非constのメソッドであるか
	@details	ID:リスト-8(手動)\n 
				コンパイルエラーとなれば成功\n
*//***********************************************************************************/
TEST(ListManualTest, Test_WhenConst)
{
#if defined TT_TEST_NOT_CONST_METHOD

	const DoublyLinkedList<RecordData> list;

	list.QuickSort(NameAscendingOrder);
	list.QuickSort(NameDescendingOrder);
	list.QuickSort(ScoreAscendingOrder);
	list.QuickSort(ScoreDescendingOrder);

#endif //TT_TEST_NOT_CONST_METHOD
	SUCCEED();
}