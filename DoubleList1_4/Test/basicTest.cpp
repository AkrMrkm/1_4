/**
* @file test.cpp
* @brief �����e�X�gcpp
* @author ����P
* @date 2023/10/19/11:30
* @details �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v
*			���̂܂܎g���񂵂ł��B
*/

#include "pch.h"
#include "basicTest.h"

using namespace auto_Test;

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== �f�[�^���̎擾 ===================================
		typedef EmptyListTest GetDataNumTestEmpty;
		typedef OneDataListTest GetDataNumTestOneData;

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-0\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
						�f�[�^������̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_WhenEmpty)
		{
			EXPECT_EQ(0, m_List->GetDataNum()) << "���X�g����ł���ꍇ�̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�����Ă���ΐ����ł��B\n
						�f�[�^������̃��X�g���g�p\n
		 *//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_InsertEnd)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			ASSERT_TRUE(m_List->Insert(it, g_data[0])); // �f�[�^���ЂƂ}��

			EXPECT_EQ(1, m_List->GetDataNum()) << "���X�g�����ւ̑}�����s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-2\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
		//*//***********************************************************************************/
		TEST(GetDataNumTest, Test_GetDataNum_InsertEnd_Failed)
		{
			// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-3\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
						�f�[�^������̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_Insert)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			ASSERT_TRUE(m_List->Insert(it, g_data[0])); // �f�[�^���ЂƂ}��

			EXPECT_EQ(1, m_List->GetDataNum()) << "�f�[�^�̑}�����s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}���Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-4\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, Test_GetDataNum_Insert_Failed)
		{
			// �}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-5\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�ŏ��Ƀf�[�^���ЂƂ}�����āA�폜���s���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestOneData, Test_GetDataNum_Remove)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			m_List->Remove(it);

			EXPECT_EQ(0, m_List->GetDataNum()) << m_List->GetDataNum() << "�f�[�^�̍폜���s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-6\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�ŏ��Ƀf�[�^���ЂƂ}�����āA�폜���s���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestOneData, Test_GetDataNum_Remove_Failed)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			m_List->Remove(it);

			EXPECT_EQ(1, m_List->GetDataNum()) << m_List->GetDataNum() << "�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�Ƀf�[�^�̍폜�������ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-7\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^�����}�C�i�X�łȂ���ΐ����ł��B\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetDataNumTestEmpty, Test_GetDataNum_Remove_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			ASSERT_FALSE(m_List->Remove(it));

			EXPECT_EQ(0, m_List->GetDataNum());
		}

		// 8�̓}�j���A���e�X�g

		//=================================== �f�[�^�̑}�� ===================================
		typedef FiveDataListTest InsertTestFiveDataList;
		typedef TwoEmptyListTest InsertTestTwoEmptyList;

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
			@details	ID:���X�g-9\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���邱��\n
						2�̋�̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(InsertTestTwoEmptyList, Test_Insert_Empty)
		{
			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				EXPECT_TRUE(m_List->Insert(it, g_data[0]));
				EXPECT_EQ(1, m_List->GetDataNum());
			}

			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List_2->end();
				EXPECT_TRUE(m_List_2->Insert(it, g_data[0]));
				EXPECT_EQ(1, m_List_2->GetDataNum());
			}
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-10\n
						�擪�ɗv�f���}������A���X�擪�������v�f���Q�ԖڂɂȂ�ΐ����ł��B\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_Begin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			// �擪��5��}��
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			//�擪�������v�f����ԖڂɂȂ��Ă����琬��(���Ԃ�501234�ɂȂ��Ă����琬��)
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
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-11\n
						�C�e���[�^�̎w���ʒu�ɗv�f���}�������\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_End)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			// ������5��}��
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			// (���Ԃ�012345�ɂȂ��Ă����琬��)
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
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����e�X�g
			@details	ID:���X�g-12\n
						TRUE�Ő���\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_Other)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			++it;
			++it;
			++it;

			// �擪����4�Ԗڂ�5��}��
			ASSERT_TRUE(m_List->Insert(it, g_data[5]));

			// (���Ԃ�012534�ɂȂ��Ă����琬��)
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
			@brief		ConstIterator���w�肵�đ}���������ۂ̋����e�X�g
			@details	ID:���X�g-13\n
						TRUE�Ő���\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩�B\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(InsertTestFiveDataList, Test_Insert_Const)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();

				// �擪�ɂT��}��
				m_List->Insert(it, g_data[5]);

				// ���Ԃ�501234�ɂȂ��Ă��琬��
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

			// 3�Ԗڂɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				++it;
				// �擪����3�ԖڂɂU��}��
				m_List->Insert(it, g_data[6]);
				// ���Ԃ�5061234�ɂȂ��Ă���TRUE
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

			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				// �����ɂV��}��
				m_List->Insert(it, g_data[7]);
				// ���Ԃ�5061234�ɂȂ��Ă���TRUE
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
			@brief		�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋����e�X�g
			@details	ID:���X�g-14\n
						���X�g�̎Q�Ƃ������C�e���[�^��n�����ۂ̋����Ȃ�\n
						�����N����Ȃ���ΐ���\n
						2�̋�̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(InsertTestTwoEmptyList, Test_Insert_Unknown)
		{
			// ��̋�̃��X�g�ɗv�f���ЂƂ}�����Ă���
			m_List->PushBack(g_data[0]);
			m_List_2->PushBack(g_data[0]);

			// ���X�g�̎Q�Ƃ������C�e���[�^��}�������Ƃ�
			DoublyLinkedList<RecordData>::Iterator it;
			EXPECT_FALSE(m_List->Insert(it, g_data[2]));
			//�f�[�^�����ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(1, (m_List->GetDataNum()));

			// ���X�g�Q�̃C�e���[�^�����X�g�P�ɓn���đ}�������Ƃ�(�ʂ̃��X�g���Q�Ƃ����Ƃ�)
			it = m_List_2->begin();
			EXPECT_FALSE(m_List->Insert(it, g_data[2]));
			//�f�[�^�����ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(1, (m_List->GetDataNum()));
		}

		// 15�̓}�j���A���e�X�g

		//=================================== �f�[�^�̍폜 ===================================
		typedef EmptyListTest RemoveTestEmpty;
		typedef FiveDataListTest RemoveTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
			@details	ID:���X�g-16\n
						FALSE�Ő���\n
						�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���邱��\n
		*//***********************************************************************************/
		TEST_F(RemoveTestEmpty, Test_Remove_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			EXPECT_FALSE(m_List->Remove(it));

			it = m_List->end();
			EXPECT_FALSE(m_List->Remove(it));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
			@details	ID:���X�g-17\n
						�擪�v�f�̍폜\n
						TRUE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_Begin)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_TRUE(m_List->Remove(it));

			// �擪�v�f���Ȃ��Ȃ��Ă���ΐ���
			// ���̃f�[�^����01234�Ȃ̂ŁA1234�ɂȂ��Ă���ΐ���
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
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
			@details	ID:���X�g-18\n
						�v�f�����ς��Ȃ����false�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_End)
		{
			const int oldNum = m_List->GetDataNum();

			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_FALSE(m_List->Remove(it));

			//�v�f�����ς���Ă��Ȃ���ΐ���
			EXPECT_FALSE((oldNum != m_List->GetDataNum())) << oldNum << m_List->GetDataNum();
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
			@details	ID:���X�g-19\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						TRUE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, TestRemoveOther)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			// 2�Ԗڂ��폜
			m_List->Remove(++it);

			it = m_List->begin();
			RecordData itData = *it;

			// ���̃f�[�^����01234�Ȃ̂ŁA0234�ɂȂ��Ă���ΐ���
			EXPECT_EQ(0, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIterator���w�肵�č폜���s�����ۂ̋���
			@details	ID:���X�g-20\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						TRUE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_Other_Const)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(it);

				it = m_List->begin();
				RecordData itData = *it;

				//���Ԃ�1234�ɂȂ��Ă���ΐ���
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// �擪����2�Ԗڂ��폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(++it);

				it = m_List->begin();
				RecordData itData = *it;

				//���Ԃ�134�ɂȂ��Ă���ΐ���
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}

			// �����C�e���[�^��n���č폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);

				it = m_List->begin();
				RecordData itData = *it;

				//���Ԃ�134�ŕς���Ă��Ȃ���ΐ���
				EXPECT_EQ(1, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}
		}
		/**********************************************************************************//**
			@brief		�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
			@details	ID:���X�g-21\n
						���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^��n�����ۂ̋����Ȃ�\n
						�����N����Ȃ�\n
						FALSE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(RemoveTestFiveData, Test_Remove_Unknown)
		{
			const int oldNum = m_List->GetDataNum();

			// �Q�Ƃ̖����C�e���[�^��n�����Ƃ�
			{
				DoublyLinkedList<RecordData>::Iterator it;
				m_List->Remove(it);
				//�f�[�^�̑������ς���Ă��Ȃ���ΐ���
				EXPECT_EQ(oldNum, m_List->GetDataNum());
			}

			// �ʂ̃��X�g�̃C�e���[�^��n�����Ƃ�
			{
				DoublyLinkedList<RecordData> list2;
				list2.PushBack(g_data[0]);
				DoublyLinkedList<RecordData>::Iterator it = list2.begin();
				m_List->Remove(it);
				//�f�[�^�̑������ς���Ă��Ȃ���ΐ���
				EXPECT_EQ(oldNum, m_List->GetDataNum());
			}
		}

		// 22�̓}�j���A���e�X�g


		//=================================== �擪�C�e���[�^�̎擾 ===================================
		typedef EmptyListTest beginTestEmpty;
		typedef OneDataListTest beginTestOneData;
		typedef FiveDataListTest beginTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-23\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(beginTestEmpty, Test_begin_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator endIt = m_List->end();

			// �擪�C�e���[�^�Ɩ����C�e���[�^����������ΐ���
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-24\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(beginTestOneData, Test_begin_One)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-25\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(beginTestFiveData, Test_begin_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-26\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(beginTestOneData, Test_begin_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				RecordData itData = *it;
				//0�������Ă���ΐ���
				EXPECT_EQ(0, (itData.m_score));
			}

			//�擪�ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->begin();
				RecordData itData = *it;
				//�擪��1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�擪����2�Ԗڂɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->begin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�����ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->begin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-27\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����̗v�f�̍폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(beginTestFiveData, Test_begin_AfterRemove)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// �擪�̂O�������āA1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				++it;
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �����̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}
		}

		// 28�̓}�j���A���e�X�g


		//=================================== �擪�R���X�g�C�e���[�^�̎擾 ===================================
		typedef EmptyListTest GetConstBeginTestEmpty;
		typedef OneDataListTest GetConstBeginTestOneData;
		typedef FiveDataListTest GetConstBeginTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-29\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestEmpty, Test_GetConstBegin_Empty)
		{
			DoublyLinkedList<RecordData>::ConstIterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::ConstIterator endIt = m_List->end();

			// �擪�C�e���[�^�Ɩ����C�e���[�^����������ΐ���
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-30\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestOneData, Test_GetConstBegin_One)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-31\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestFiveData, Test_GetConstBegin_Any)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();

			RecordData itData = *it;

			EXPECT_EQ(0, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-32\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestOneData, Test_GetConstBegin_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				RecordData itData = *it;
				//0�������Ă���ΐ���
				EXPECT_EQ(0, (itData.m_score));
			}

			//�擪�ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->begin();
				RecordData itData = *it;
				//�擪��1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�擪����2�Ԗڂɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->begin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}

			//�����ɑ}��������̊m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->begin();
				RecordData itData = *it;
				//�擪��1�����̂܂ܓ����Ă����OK
				EXPECT_EQ(1, (itData.m_score));
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-33\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstBeginTestFiveData, Test_GetConstBegin_AfterRemove)
		{
			// ���̃f�[�^�̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// �擪�̂O�������āA1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}

			// �����̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->begin();
				RecordData itData = *it;
				// 1�������Ă����OK
				EXPECT_EQ(1, (itData.m_score)) << (itData.m_score);
			}
		}

		// 34�̓}�j���A���e�X�g


		//=================================== �����C�e���[�^�̎擾 ===================================
		typedef EmptyListTest endTestEmpty;
		typedef OneDataListTest endTestOneData;
		typedef FiveDataListTest endTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-35\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EmptyListTest, Test_end_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator endIt = m_List->end();

			// �擪�C�e���[�^�Ɩ����C�e���[�^����������ΐ���
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-36\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(endTestOneData, Test_end_One)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			// �����C�e���[�^�̑O�̗v�f���ŏ��ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-37\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(endTestFiveData, Test_end_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			// ���̃f�[�^�̃X�R�A����01234�Ȃ̂�
			// �����C�e���[�^�̑O�̗v�f��4�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-38\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(endTestOneData, Test_end_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, (itData.m_score)); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// 2�Ԗڂɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�̂܂܂������琬��
			}

			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-39\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(endTestFiveData, Test_end_AfterRemove)
		{
			// ���̃f�[�^���̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
				m_List->Remove(++it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �����C�e���[�^�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
				// �����C�e���[�^�̓_�~�[�m�[�h�Ȃ̂ŕς��Ȃ�
			}

			// �����C�e���[�^�̂ЂƂO�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::Iterator it = m_List->end();
				m_List->Remove(--it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		//40�̓}�j���A���e�X�g


		//=================================== �����R���X�g�C�e���[�^�̎擾 ===================================
		typedef EmptyListTest GetConstEndTestEmpty;
		typedef OneDataListTest GetConstEndTestOneData;
		typedef FiveDataListTest GetConstEndTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-41\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
						�f�[�^����̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestEmpty, Test_GetConstEnd_Empty)
		{
			DoublyLinkedList<RecordData>::ConstIterator beginIt = m_List->begin();
			DoublyLinkedList<RecordData>::ConstIterator endIt = m_List->end();

			// �擪�C�e���[�^�Ɩ����C�e���[�^����������ΐ���
			EXPECT_TRUE(beginIt == endIt);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-42\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestOneData, Test_GetConstEnd_One)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();

			// �����C�e���[�^�̑O�̗v�f���ŏ��ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(0, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-43\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestFiveData, Test_GetConstEnd_Any)
		{
			DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();

			// ���̃f�[�^�̃X�R�A����01234�Ȃ̂�
			// �����C�e���[�^�̑O�̗v�f��4�ł������琬��
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-44\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestOneData, Test_GetConstEnd_AfterInsert)
		{
			// ����������Ă���f�[�^���m�F
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, (itData.m_score)); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// �擪�ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Insert(it, g_data[1]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�������琬��
			}

			// 2�Ԗڂɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				++it;
				m_List->Insert(it, g_data[2]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(0, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��0�̂܂܂������琬��
			}

			// �����ɑ}��
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Insert(it, g_data[3]);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-45\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetConstEndTestFiveData, Test_GetConstEnd_AfterRemove)
		{
			// ���̃f�[�^���̃X�R�A����01234
			// �擪�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �擪����2�Ԗڂ̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->begin();
				m_List->Remove(++it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			}

			// �����C�e���[�^�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
				// �����C�e���[�^�̓_�~�[�m�[�h�Ȃ̂ŕς��Ȃ�
			}

			// �����C�e���[�^�̂ЂƂO�̗v�f���폜
			{
				DoublyLinkedList<RecordData>::ConstIterator it = m_List->end();
				m_List->Remove(--it);
				it = m_List->end();
				RecordData itData = *(--it);
				EXPECT_EQ(3, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��3�������琬��
			}
		}

		//46�̓}�j���A���e�X�g
	}

	//=====================================================================================================
	//=====================================================================================================
	//=====================================================================================================

	namespace chapter2
	{
		//===================================�C�e���[�^�̎w���v�f�̎擾 ===================================
		typedef EmptyListTest GetItTestEmpty;
		typedef OneDataListTest GetItTestOneData;

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-0\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetItTestEmpty, Test_GetIt_NoReference)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(*it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
			@details	ID:���X�g-1\n
						�����ɍēx�Ăяo���A�l���ύX����Ă��邱�Ƃ��m�F\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetItTestOneData, Test_GetIt_Assign)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			*it = g_data[1]; // �ʂ̃f�[�^����
			RecordData itData = *it;

			// �P�������Ă���ΐ���
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-3\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetItTestEmpty, Test_GetIt_EmptyBegin)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_DEATH(*it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-4\n
						Assert����\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(GetItTestOneData, Test_GetIt_EmptyEnd)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_DEATH(*it, ".*"); // �_�~�[�m�[�h���w���̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		//===================================�C�e���[�^�����X�g�̖����Ɍ������ĂЂƂi�߂�===================================
		typedef EmptyListTest IncrementTestEmpty;
		typedef OneDataListTest IncrementTestOneData;
		typedef FiveDataListTest IncrementTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-5\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(IncrementTestEmpty, Test_Increment_NoReference)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(++it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-6\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(IncrementTestEmpty, Test_Increment_TestEmptyBegin)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_DEATH(++it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-7\n
						Assert����\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(IncrementTestOneData, Test_Increment_EndIt)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_DEATH(++it, ".*"); // �_�~�[�m�[�h���w���̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
			@details	ID:���X�g-8\n
						���̗v�f���w��\n
						���X�g�̐擪���疖���܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(IncrementTestFiveData, Test_Increment_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			RecordData itData = *it;

			// 01234�ł���ΐ���
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
			@brief		�O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-9\n
						���̗v�f���w��\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(IncrementTestFiveData, Test_Increment_PrefIncrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			RecordData itData = *it;

			// 01234�ł���ΐ���
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
			@brief		��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-10\n
						���̗v�f���w��\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(IncrementTestFiveData, Test_Increment_BackIncrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			RecordData itData = *it;

			// 00123�ł���ΐ���
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


		//===================================�C�e���[�^�����X�g�̐擪�Ɍ������ĂЂƂi�߂�===================================
		typedef EmptyListTest DecrementTestEmpty;
		typedef OneDataListTest DecrementTestOneData;
		typedef FiveDataListTest DecrementTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-11\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(DecrementTestEmpty, Test_Decrement_NoReference)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it;

			EXPECT_DEATH(--it, ".*"); // ���X�g�̎Q�Ƃ��Ȃ��̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-12\n
						Assert����\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(DecrementTestEmpty, Test_Decrement_EmptyEnd)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();

			EXPECT_DEATH(--it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-13\n
						Assert����\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(DecrementTestOneData, Test_Decrement_BeginIt)
		{
#ifdef _DEBUG
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();

			EXPECT_DEATH(--it, ".*"); // �_�~�[�m�[�h���w���̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
#endif //_DEBUG
		}
		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
			@details	ID:���X�g-14\n
						�O�̗v�f���w��\n
						���X�g�̖�������擪�܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(DecrementTestFiveData, Test_Decrement_Any)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();
			RecordData itData = *(--it);

			// 43210�ł���ΐ���
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
			@brief		�O�u�f�N�������g�s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-15\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(DecrementTestFiveData, Test_Decrement_PrefDecrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();
			RecordData itData = *(--it);

			// 43210�ł���ΐ���
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
			@brief		��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-16\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(DecrementTestFiveData, Test_Decrement_BackDecrement)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->end();
			RecordData itData = *(--it);

			// 44321�ł���ΐ���
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

		//17�̓}�j���A���e�X�g

		//===================================�C�e���[�^�̃R�s�[���s��===================================
		typedef OneDataListTest CopyTestOneData;
		/**********************************************************************************//**
			@brief		�C�e���[�^�̃R�s�[���s��
			@details	ID:���X�g-18\n
						�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
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

		//19�̓}�j���A���e�X�g

		//===================================�C�e���[�^�̑�����s��===================================
		typedef FiveDataListTest AssignTestFiveData;
		/**********************************************************************************//**
			@brief		�C�e���[�^�̑�����s��
			@details	ID:���X�g-20\n
						�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
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


		//===================================�ӂ��̃C�e���[�^������̂��̂ł��邩��r===================================
		typedef EmptyListTest    EqualTestEmpty;
		typedef OneDataListTest  EqualTestOneData;
		typedef FiveDataListTest EqualTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
			@details	ID:���X�g-21\n
						TRUE�Ő���\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EqualTestEmpty, Test_Equal_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->end();

			EXPECT_TRUE(it == it2);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-22\n
						TRUE�Ő���\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EqualTestOneData, Test_Equal_Same)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();

			EXPECT_TRUE(it == it2);
		}

		/**********************************************************************************//**
			@brief		�قȂ�C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-23\n
						FALSE�Ő���\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(EqualTestFiveData, Test_Equal_Diff)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();
			++it2;

			EXPECT_FALSE(it == it2);
		}


		//===================================�ӂ��̃C�e���[�^���قȂ���̂ł��邩��r===================================
		typedef EmptyListTest    NotEqualTestEmpty;
		typedef OneDataListTest  NotEqualTestOneData;
		typedef FiveDataListTest NotEqualTestFiveData;

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
			@details	ID:���X�g-24\n
						��̃��X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(NotEqualTestEmpty, Test_NotEqual_Empty)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->end();

			EXPECT_FALSE(it != it2);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-25\n
						�f�[�^���ЂƂi�[���ꂽ���X�g���g�p\n
		*//***********************************************************************************/
		TEST_F(NotEqualTestOneData, Test_NotEqual)
		{
			DoublyLinkedList<RecordData>::Iterator it = m_List->begin();
			DoublyLinkedList<RecordData>::Iterator it2 = m_List->begin();

			EXPECT_FALSE(it != it2);
		}

		/**********************************************************************************//**
			@brief		�قȂ�C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-26\n
						5�̃f�[�^���i�[���ꂽ���X�g���g�p\n
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