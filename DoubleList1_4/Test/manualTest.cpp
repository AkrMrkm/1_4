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
	@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-8(�蓮)\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TT_TEST_GET_DATA_NUM_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
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
	@brief		���X�g�����̃f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
	@details	ID:���X�g-15(�蓮)\n
				���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
				��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Insert_WhenConst)
{
#if defined TT_TEST_INSERT_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.begin();
	RecordData data{ 1, "a" };
	list.Insert(it, data);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g-22\

				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Remove_WhenConst)
{
#if defined TT_TEST_REMOVE_WHEN_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator it = list.begin();
	list.Remove(it); // �����ŃG���[
#endif //TT_TEST_REMOVE_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	@details	ID:���X�g-28\n
				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(ListManualTest, Testbegin_Const)
{
#if defined TT_TEST_BEGIN_WHEN_NO_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::Iterator it = list.begin();// �����ŃG���[
#endif //TT_TEST_BEGIN_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g-34\n
				�R���p�C���G���[���ʂ�ΐ���\n
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
	@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	@details	ID:���X�g-40\n
				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(ListManualTest, Test_end_Const)
{
#if defined TT_TEST_END_WHEN_NO_CONST
	const DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::Iterator it = list.end();// �����ŃG���[
#endif //TT_TEST_END_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g-46\n
				�R���p�C�����ʂ�ΐ���\n
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
	@brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
	@details	ID:���X�g-2\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B\n
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



//===================================�C�e���[�^�̃R�s�[���s��===================================

/**********************************************************************************//**
	@brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
	@details	ID:���X�g-17\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
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




//===================================�C�e���[�^�̑�����s��===================================

/**********************************************************************************//**
	@brief		Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
	@details	ID:���X�g-19\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
*//***********************************************************************************/
TEST(ListManualTest, Test_Assign_Const)
{
#if defined TT_TEST_ASSIGN_WHEN_CONST
	DoublyLinkedList<RecordData> list;
	DoublyLinkedList<RecordData>::ConstIterator cit = list.begin();
	DoublyLinkedList<RecordData>::Iterator it = list.begin();
	it = cit; // �����ŃG���[
#endif //TT_TEST_ASSIGN_WHEN_CONST
	SUCCEED();
}

//====================================�\�[�g�e�X�g===============================================

/**********************************************************************************//**
	@brief		�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋���
	@details	ID:���X�g-7(�蓮)\n 
				�R���p�C���G���[�ƂȂ�ΐ���\n
*//***********************************************************************************/

// �s�K�؂ȃL�[
bool IntAscendingOrder(const int& a, const int& b) { return a < b; };

// ���O�ŏ���
bool NameAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_name < b.m_name; };

// ���O�ō~��
bool NameDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_name > b.m_name; };

// �X�R�A�ŏ���
bool ScoreAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_score < b.m_score; };

// �X�R�A�ō~��
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
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g-8(�蓮)\n 
				�R���p�C���G���[�ƂȂ�ΐ���\n
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