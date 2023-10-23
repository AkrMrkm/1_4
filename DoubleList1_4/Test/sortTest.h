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
	//! ���O�ŏ���
	bool NameAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_name < b.m_name; };

	//! ���O�ō~��
	bool NameDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_name > b.m_name; };

	//! �X�R�A�ŏ���
	bool ScoreAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_score < b.m_score; };

	//! �X�R�A�ō~��
	bool ScoreDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_score > b.m_score; };

	/**
	* @brief    �d�������̃o���o���̃f�[�^���i�[���ꂽ��Ԃɏ���������֐�
	* @details  �����e�X�g�p�̏������֐��ł��B\n
	*			(4275108936)�̏��Ńf�[�^���i�[���܂��B\n
	*			(cadjhifegb)�̏��Ńf�[�^���i�[���܂��B\n
	*/
	void InitListNoSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 4, "c" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 7, "d" });
		list.PushBack({ 5, "j" });
		list.PushBack({ 1, "h" });
		list.PushBack({ 0, "i" });
		list.PushBack({ 8, "f" });
		list.PushBack({ 9, "e" });
		list.PushBack({ 3, "g" });
		list.PushBack({ 6, "b" });
	}

	/**
	* @brief    �d���L��̃o���o���̃f�[�^���i�[���ꂽ��Ԃɏ���������֐�
	* @details  �����e�X�g�p�̏������֐��ł��B\n
	*			(1105382244)�̏��Ńf�[�^���i�[���܂��B\n
	*			(afacbbaded)�̏��Ńf�[�^���i�[���܂��B\n
	*/
	void InitListSameKey(DoublyLinkedList<RecordData>& list)
	{
		list.PushBack({ 1, "a" });
		list.PushBack({ 1, "f" });
		list.PushBack({ 0, "a" });
		list.PushBack({ 5, "c" });
		list.PushBack({ 3, "b" });
		list.PushBack({ 8, "b" });
		list.PushBack({ 2, "a" });
		list.PushBack({ 2, "d" });
		list.PushBack({ 4, "e" });
		list.PushBack({ 4, "d" });
	}
}