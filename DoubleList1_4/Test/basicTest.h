/**
* @file test.h
* @brief �����e�X�g�w�b�_�[
* @author ����P
* @date 2023/10/19/11:30
* @details  �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v\n
*			�e�X�g�t�B�N�X�`���N���X�̎���\n
*			���̂܂܎g���񂵂ł��B
*/
#pragma once

#include "../DoubleList1_4/doublyLinkedList.h"
#include "../DoubleList1_4/recordData.h"

namespace auto_Test
{
	//! �O���[�o���̐��уf�[�^(10��)
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
	* @brief �e�X�g�t�B�N�X�`���N���X
	* @details �f�[�^����̃��X�g
	*/
	class EmptyListTest : public ::testing::Test
	{
	protected:
		//! ���X�g�̃|�C���^
		DoublyLinkedList<RecordData>* m_List;

		/**
		* @brief ������
		*/
		virtual void SetUp()
		{
			m_List = new DoublyLinkedList<RecordData>();
		}

		/**
		* @brief �㏈��
		*/
		virtual void TearDown()
		{
			delete m_List;
		}
	};

	/**
	* @brief �f�[�^���ЂƂi�[���ꂽ���X�g
	* @details �X�R�A��0�̃f�[�^���i�[����Ă��܂�
	*/
	class OneDataListTest : public EmptyListTest
	{
	protected:
		/**
		* @brief ������
		* @details �X�R�A��0�̃f�[�^���i�[
		*/
		void SetUp() override
		{
			m_List = new DoublyLinkedList<RecordData>();
			m_List->PushBack(g_data[0]);
		}
	};

	/**
	* @brief �f�[�^��5�i�[���ꂽ���X�g
	* @details �X�R�A��01234�̏��Ńf�[�^���i�[����Ă��܂�
	*/
	class FiveDataListTest : public EmptyListTest
	{
	protected:
		/**
		* @brief ������
		* @details �X�R�A��0~4�̃f�[�^��5�i�[
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
	* @brief �f�[�^����̃��X�g���ʂ�2����N���X
	*/
	class TwoEmptyListTest : public EmptyListTest
	{
	protected:
		//! ���X�g2�̃|�C���^
		DoublyLinkedList<RecordData>* m_List_2;

		/**
		* @brief ������
		*/
		void SetUp() override
		{
			m_List = new DoublyLinkedList<RecordData>();
			m_List_2 = new DoublyLinkedList<RecordData>();
		}

		/**
		* @brief �㏈��
		*/
		void TearDown() override
		{
			delete m_List;
			delete m_List_2;
		}
	};

}