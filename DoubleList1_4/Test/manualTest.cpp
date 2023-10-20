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
	@brief		型などが不適切なキー指定が引数で渡された時の挙動
	@details	ID:リスト-7(手動)\n 
				コンパイルエラーとなれば成功\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Unknown)
{
#if defined TT_TEST_UNKNOWN

	DoublyLinkedList<RecordData> list;

	DoublyLinkedList<int>::Iterator it;
	DoublyLinkedList<char>::Iterator it2;

	auto cmp = [](int a, int b) { return a < b; };

	list.QuickSort(it, it2, cmp);

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

	DoublyLinkedList<RecordData>::ConstIterator beginIt = list.begin();
	DoublyLinkedList<RecordData>::ConstIterator endIt = list.end();

	auto cmp = [](RecordData a, RecordData b) { return a < b; };

	list.QuickSort(beginIt, endIt, cmp);

#endif //TT_TEST_NOT_CONST_METHOD
	SUCCEED();
}