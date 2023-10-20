/**
* @file	    test.h
* @brief    �e�X�g�w�b�_�[
* @author   ����P
* @date     2023/10/20/11:00
* @details  �ۑ�1_4�u�N�C�b�N�\�[�g�̎����v\n
			�����e�X�g�Ŏg���A���X�g�ɓ���̃f�[�^���i�[���鏉�����֐����L�q���Ă��܂��B\n
*/

#pragma once

#include "../DoubleList1_4/doublyLinkedList.h"
#include "../DoubleList1_4/recordData.h"

namespace auto_test
{
	/**
	* @brief    �d�������̃o���o���̃f�[�^���i�[���ꂽ��Ԃɏ���������֐�
	* @details  �����e�X�g�p�̏������֐��ł��B\n
	*			(4275108936)�̏��Ńf�[�^���i�[���܂��B\n
	*/
	void ListInitNoSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 4, "a" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 7, "a" });
		list.PushBack({ 5, "a" });
		list.PushBack({ 1, "a" });
		list.PushBack({ 0, "a" });
		list.PushBack({ 8, "a" });
		list.PushBack({ 9, "a" });
		list.PushBack({ 3, "a" });
		list.PushBack({ 6, "a" });
	}

	/**
	* @brief    �d���L��̃o���o���̃f�[�^���i�[���ꂽ��Ԃɏ���������֐�
	* @details  �����e�X�g�p�̏������֐��ł��B\n
	*			(1105382244)�̏��Ńf�[�^���i�[���܂��B\n
	*/
	void ListInitSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 1, "a" });
		list.PushBack({ 1, "a" });
		list.PushBack({ 0, "a" });
		list.PushBack({ 5, "a" });
		list.PushBack({ 3, "a" });
		list.PushBack({ 8, "a" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 4, "a" });
		list.PushBack({ 4, "a" });
	}


	/**
	* @brief     �f�[�^�𐮗񂵂���Ԃɏ���������֐�
	* @param[in] list ���������郊�X�g
	* @param[in] isAscendingOrder true�Ȃ�Ώ����Afalse�Ȃ�΍~���Ŋi�[���܂��B\n
	* @details   �����e�X�g�p�̏������֐��ł��B\n
	*			 0�`9���i�[���܂��B\n
	*/
	void ListInitLinedUp(DoublyLinkedList<RecordData>& list, bool isAscendingOrder)
	{
		// ���X�g����ɂ���
		{
			DoublyLinkedList<RecordData>::Iterator it = list.begin();
			auto endIt = list.end();
			for (auto it = list.begin(); it != endIt; it++)
			{
				list.Remove(it);
			}
		}

		if (isAscendingOrder)
			for (int i = 0; i < 10; i++)
			{
				list.PushBack({ i, "a" });
			}
		else
			for (int i = 9; i >= 0; i--)
			{
				list.PushBack({ i, "a" });
			}
	}
}