/**
* @file manualTest.h
* @brief �蓮�e�X�gcpp
* @author ����P
* @date 2023/10/19/11:30
* @details �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v\n
*/

#include "pch.h"
#include "manualTest.h"
#include "../DoubleList1_4/doublyLinkedList.h"
#include "../DoubleList1_4/recordData.h"

/**********************************************************************************//**
	@brief		�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋���
	@details	ID:���X�g-7(�蓮)\n 
				�R���p�C���G���[�ƂȂ�ΐ���\n
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
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g-8(�蓮)\n 
				�R���p�C���G���[�ƂȂ�ΐ���\n
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