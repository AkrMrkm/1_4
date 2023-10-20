/**
* @file		test.cpp
* @brief	�����e�X�gcpp
* @author	����P
* @date		2023/10/20/12:00
* @details  �ۑ�1_4�u�N�C�b�N�\�[�g�v
*/

#include "pch.h"
#include "test.h"

using namespace auto_test;

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== �N�C�b�N�\�[�g ===================================

		/**********************************************************************************//**
			@brief		�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋���
			@details	ID:���X�g-0\n
						�G���[�܂߂āA�����N����Ȃ���ΐ���\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_Empty)
		{
			// ��̃��X�g���쐬
			DoublyLinkedList<RecordData> list;

			/* ���� */
			{
				DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
				DoublyLinkedList<RecordData>::Iterator endIt = list.end();

				auto cmp = [](RecordData a, RecordData b) { return a < b; };

				list.QuickSort(beginIt, endIt, cmp);

				EXPECT_EQ(0, list.GetDataNum());
			}

			/* �~�� */
			{
				DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
				DoublyLinkedList<RecordData>::Iterator endIt = list.end();

				auto cmp = [](RecordData a, RecordData b) { return a > b; };

				list.QuickSort(beginIt, endIt, cmp);

				EXPECT_EQ(0, list.GetDataNum());
			}
		}

		/**********************************************************************************//**
			@brief		�v�f��1���������X�g�Ƀ\�[�g�����s�������̋���
			@details	ID:���X�g-1\n
						�G���[�܂߂āA�����N����Ȃ���ΐ���\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_OneData)
		{
			// �ЂƂ̃f�[�^���i�[�������X�g
			DoublyLinkedList<RecordData> list;
			list.PushBack({1,"a"});

			/* ���� */
			{
				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					RecordData data = *it;
					EXPECT_EQ(1, data.m_score);
				}
			}

			/* �~�� */
			{
				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					RecordData data = *it;
					EXPECT_EQ(1, data.m_score);
				}
			}
		}

		/**********************************************************************************//**
			@brief		2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋���
			@details	ID:���X�g-2\n
						�v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ���\n
						�擪���珇�ɃC�e���[�^�Ŋm�F���A�m�[�h�̍����ւ�������ɍs���Ă��邩�`�F�b�N\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_AnyData)
		{
			/* ���� */
			{
				DoublyLinkedList<RecordData> list;

				// ���X�g�ɏd�������̃f�[�^��0�`9�܂ł̐�����10�i�[����
				ListInitNoSameKey(list);

				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F(�f�[�^����0123456789�ɂȂ��Ă���ΐ���)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(i, data.m_score);
					}
				}
			}

			/* �~�� */
			{
				DoublyLinkedList<RecordData> list;

				// ���X�g�ɏd�������̃f�[�^��0�`9�܂ł̐�����10�i�[����
				ListInitNoSameKey(list);

				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F(�f�[�^����9876543210�ɂȂ��Ă���ΐ���)
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
			@brief		�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋���
			@details	ID:���X�g-3\n
						�v�f���\�[�g����ĕ��Ԃ��A�����v�f�̏����͕ۏ؂���Ȃ�\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_SameKey)
		{
			// �f�[�^�m�F�p�̐��񂳂ꂽ�f�[�^���̒萔
			const int orderNumber[10] = { 0,1,1,2,2,3,4,4,5,8 };

			/* ���� */
			{
				DoublyLinkedList<RecordData> list;

				//(1105382244)�̏��Ńf�[�^���i�[���܂�
				ListInitSameKey(list);

				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F(�f�[�^����0112234458�ɂȂ��Ă���ΐ���)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(orderNumber[i], data.m_score);
					}
				}
			}

			/* �~�� */
			{
				DoublyLinkedList<RecordData> list;

				//(1105382244)�̏��Ńf�[�^���i�[���܂�
				ListInitSameKey(list);

				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F(�f�[�^����8544322110�ɂȂ��Ă���ΐ���)
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
			@brief		����ς݃��X�g�Ƀ\�[�g�����s�������̋���
			@details	ID:���X�g-4\n
						�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ�\n
						�d���v�f�Ȃ��̐���ς݃��X�g���g��\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_LineUp_Again)
		{
			/* ���� */
			{
				DoublyLinkedList<RecordData> list;

				// ���X�g��(0123456789)�Ə����Ő��񂳂ꂽ�f�[�^���i�[����
				ListInitLinedUp(list, true);

				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a < b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F(�f�[�^����0123456789�ƕς���Ă��Ȃ���ΐ���)
				{
					DoublyLinkedList<RecordData>::Iterator it = list.begin();
					for (int i = 0; i < 10; i++, it++)
					{
						RecordData data = *it;
						EXPECT_EQ(i, data.m_score);
					}
				}
			}

			/* �~�� */
			{
				DoublyLinkedList<RecordData> list;

				// ���X�g��(9876543210)�ƍ~���Ő��񂳂ꂽ�f�[�^���i�[����
				ListInitLinedUp(list, false);

				// �\�[�g
				{
					DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
					DoublyLinkedList<RecordData>::Iterator endIt = list.end();

					auto cmp = [](RecordData a, RecordData b) { return a > b; };

					list.QuickSort(beginIt, endIt, cmp);
				}

				// �f�[�^�̊m�F(�f�[�^����9876543210�ƕς���Ă��Ȃ���ΐ���)
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
			@brief		��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋���
			@details	ID:���X�g-5\n
						�v�f���\�[�g����ĕ���\n
						�d���v�f�Ȃ��̐���ς݃��X�g���g��\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_LineUp_AfterInsert)
		{
			/* ���� */
			{
				/* �擪�ɑ}�� */
				{
					DoublyLinkedList<RecordData> list;

					// ���X�g��(0123456789)�Ə����Ő��񂳂ꂽ�f�[�^���i�[����
					ListInitLinedUp(list, true);

					// �擪��{10}��}��
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						list.Insert(it, { 10, "a"});
					}

					// �\�[�g
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a < b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// �f�[�^�̊m�F(�f�[�^����0,1,2,3,4,5,6,7,8,9,10�ƂȂ��Ă���ΐ���)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(i, data.m_score);
						}
					}
				}
				/* �擪����3�Ԗڂɑ}�� */
				{
					DoublyLinkedList<RecordData> list;

					// ���X�g��(0123456789)�Ə����Ő��񂳂ꂽ�f�[�^���i�[����
					ListInitLinedUp(list, true);

					// �擪����3�Ԗڂ�{10}��}��
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						++it; 
						++it;
						list.Insert(it, { 10, "a"});
					}

					// �\�[�g
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a < b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// �f�[�^�̊m�F(�f�[�^����0,1,2,3,4,5,6,7,8,9,10�ƂȂ��Ă���ΐ���)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(i, data.m_score);
						}
					}
				}
				/* �����ɑ}�� */
				{
					DoublyLinkedList<RecordData> list;

					// ���X�g��(0123456789)�Ə����Ő��񂳂ꂽ�f�[�^���i�[����
					ListInitLinedUp(list, true);

					// ������{10}��}��
					{
						DoublyLinkedList<RecordData>::Iterator it = list.end();
						list.Insert(it, { 10, "a"});
					}

					// �\�[�g
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a < b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// �f�[�^�̊m�F(�f�[�^����0,1,2,3,4,5,6,7,8,9,10�ƂȂ��Ă���ΐ���)
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
			/* �~�� */
			{
				/* �擪�ɑ}�� */
				{
					DoublyLinkedList<RecordData> list;

					// ���X�g��(9876543210)�ƍ~���Ő��񂳂ꂽ�f�[�^���i�[����
					ListInitLinedUp(list, false);

					// �擪��{10}��}��
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						list.Insert(it, { 10, "a"});
					}

					// �\�[�g
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a > b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// �f�[�^�̊m�F(�f�[�^����10,9,8,7,6,5,4,3,2,1,0�ƂȂ��Ă���ΐ���)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(10 - i, data.m_score);
						}
					}
				}
				/* �擪����3�Ԗڂɑ}�� */
				{
					DoublyLinkedList<RecordData> list;

					// ���X�g��(9876543210)�ƍ~���Ő��񂳂ꂽ�f�[�^���i�[����
					ListInitLinedUp(list, false);

					// �擪����3�Ԗڂ�{10}��}��
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						++it; 
						++it;
						list.Insert(it, { 10, "a"});
					}

					// �\�[�g
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a > b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// �f�[�^�̊m�F(�f�[�^����10,9,8,7,6,5,4,3,2,1,0�ƂȂ��Ă���ΐ���)
					{
						DoublyLinkedList<RecordData>::Iterator it = list.begin();
						for (int i = 0; i <= 10; i++, it++)
						{
							RecordData data = *it;
							EXPECT_EQ(10 - i, data.m_score);
						}
					}
				}
				/* �����ɑ}�� */
				{
					DoublyLinkedList<RecordData> list;

					// ���X�g��(9876543210)�ƍ~���Ő��񂳂ꂽ�f�[�^���i�[����
					ListInitLinedUp(list, false);

					// ������{10}��}��
					{
						DoublyLinkedList<RecordData>::Iterator it = list.end();
						list.Insert(it, { 10, "a"});
					}

					// �\�[�g
					{
						DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
						DoublyLinkedList<RecordData>::Iterator endIt = list.end();

						auto cmp = [](RecordData a, RecordData b) { return a > b; };

						list.QuickSort(beginIt, endIt, cmp);
					}

					// �f�[�^�̊m�F(�f�[�^����10,9,8,7,6,5,4,3,2,1,0�ƂȂ��Ă���ΐ���)
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
			@brief		�L�[�w������Ȃ�����(nullptr��n����)���̋���\
			@details	ID:���X�g-6\n
						�G���[�܂߂āA�����N����Ȃ���ΐ���\n
		*//***********************************************************************************/
		TEST(QuickSortTest, Test_Null)
		{
			DoublyLinkedList<RecordData> list;

			// �f�[�^��1,3,2�̏��Ŋi�[
			list.PushBack({ 1,"a" });
			list.PushBack({ 3,"a" });
			list.PushBack({ 2,"a" });

			/* ���� */
			{
				// �Q�Ƃ̂Ȃ��C�e���[�^��n��
				DoublyLinkedList<RecordData>::Iterator beginIt;
				DoublyLinkedList<RecordData>::Iterator endIt;

				auto cmp = [](RecordData a, RecordData b) { return a < b; };

				list.QuickSort(beginIt, endIt, cmp);

				// �f�[�^�̊m�F(�f�[�^����1,3,2�̂܂܂ł���ΐ���)
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

			/* �~�� */
			{
				// �Q�Ƃ̂Ȃ��C�e���[�^��n��
				DoublyLinkedList<RecordData>::Iterator beginIt;
				DoublyLinkedList<RecordData>::Iterator endIt;

				auto cmp = [](RecordData a, RecordData b) { return a > b; };

				list.QuickSort(beginIt, endIt, cmp);

				// �f�[�^�̊m�F(�f�[�^����1,3,2�̂܂܂ł���ΐ���)
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