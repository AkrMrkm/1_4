/**
* @file		doublyLinkedList.inl
* @brief	�o�������X�g�N���X����
* @author	����P
* @date		2023/10/20/12:00
* @details  �ۑ�1_4�u�N�C�b�N�\�[�g�v
*/

#pragma once

#include <assert.h>
#include "doublyLinkedList.h"

//===============================================================
/*�o�������X�g�N���X*/


// �o�������X�g�N���X�̃R���X�g���N�^
template<typename DATA>
inline DoublyLinkedList<DATA>::DoublyLinkedList() : m_DataNum(0)
{
	m_DummyNode = new Node();
	m_DummyNode->m_next = m_DummyNode;
	m_DummyNode->m_prev = m_DummyNode;
}

// �o�������X�g�N���X�̃f�X�g���N�^
template<typename DATA>
inline DoublyLinkedList<DATA>::~DoublyLinkedList()
{
	Node* node = m_DummyNode->m_next;
	while (node != m_DummyNode)
	{
		Node* temp = node;
		node = node->m_next;
		delete temp;
	}
	delete m_DummyNode;
}

// �f�[�^���̎擾
template<typename DATA>
inline int DoublyLinkedList<DATA>::GetDataNum() const
{
	return m_DataNum;
}

// �f�[�^�̑}��
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Insert(ConstIterator & it, const DATA & data)
{
	if (it.m_List != this) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return

	Node* newNode = new Node(data); // �V�m�[�h

	Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

	// �V�m�[�h�̑O�m�[�h���C�e���[�^�̎w���O�m�[�h�ɁB
	newNode->m_prev = itNode->m_prev;

	// �V�m�[�h�̎��m�[�h���C�e���[�^�̎w���m�[�h�ɁB
	newNode->m_next = itNode;

	// �C�e���[�^�̎w���m�[�h�̑O�m�[�h�̎��̃m�[�h�ɐV�m�[�h���i�[
	// (�C�e���[�^�m�[�h�ƑO�m�[�h�̊ԂɊi�[)
	itNode->m_prev->m_next = newNode;

	// �C�e���[�^�̎w���m�[�h�̑O�m�[�h�ɐV�m�[�h���i�[�A����Ńf�[�^���q����
	itNode->m_prev = newNode;

	// �f�[�^���𑝂₷
	m_DataNum++;

	return true;
}

// �f�[�^�̒ǉ�
template<typename DATA>
inline void DoublyLinkedList<DATA>::PushBack(const DATA & data)
{
	DoublyLinkedList<DATA>::ConstIterator endIt = end();
	Insert(endIt, data);
}

// �f�[�^�̍폜
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Remove(ConstIterator & it)
{
	Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h
	if (m_DataNum == 0) return false;
	if (itNode == m_DummyNode) return false;
	if (it.m_List != this) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return

	itNode->m_prev->m_next = itNode->m_next;
	itNode->m_next->m_prev = itNode->m_prev;

	delete itNode;
	m_DataNum--;
	return true;
}

// �擪�C�e���[�^�擾
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::begin()
{
	return Iterator(m_DummyNode->m_next, this);
}

// �擪�R���X�g�C�e���[�^�擾
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::begin() const
{
	return ConstIterator(m_DummyNode->m_next, this);
}

// �����C�e���[�^�擾
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::end()
{
	return Iterator(m_DummyNode, this);
}

// �����R���X�g�C�e���[�^�擾
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::end() const
{
	return ConstIterator(m_DummyNode, this);
}

// �N�C�b�N�\�[�g
// �N�C�b�N�\�[�g�̃A���S���Y���A�R�[�h���Q�l�ɂ����T�C�g https://daeudaeu.com/quicksort/
// ��r�֐��A�����_���ɂ��ĎQ�l�ɂ����T�C�g https://qiita.com/threecups/items/aa1923a9922dc0a7abfe
template<typename DATA>
template<typename T>
inline void DoublyLinkedList<DATA>::QuickSort(ConstIterator& left, ConstIterator& right, T cmp)
{
	// �v�f���󂾂�����I��
	if (m_DummyNode == m_DummyNode->m_prev) return;

	// �E�[�̃C�e���[�^�������C�e���[�^�ł�������A�ЂƂ̍��ɕς���
	if (right == end()) --right;

	// ����ւ������I��
	if (right == left) return;
	if (left.m_Node == right.m_Node->m_next) return;

	// ����ւ�����
	Node* pivot = Partition(left.m_Node, right.m_Node, cmp);

	// Partition()�ŕԂ��Ă�����l�����ƂɂQ�ɕ������āA�ēx�N�C�b�N�\�[�g���s��
	ConstIterator it = ConstIterator(pivot->m_prev, this);
	ConstIterator it2 = ConstIterator(pivot->m_next, this);
	QuickSort(left, it, cmp);
	QuickSort(it2, right, cmp);
}

// �m�[�h�̎��f�[�^�����ւ���֐�
template<typename DATA>
inline void DoublyLinkedList<DATA>::Swap(Node* node1, Node* node2)
{
	DATA temp = node1->m_data;

	node1->m_data = node2->m_data;

	node2->m_data = temp;
}

// ��l�����Ƃɕ������ē���ւ��Ċ�l��Ԃ��֐�
template<typename DATA>
template<typename T>
inline typename DoublyLinkedList<DATA>::Node* DoublyLinkedList<DATA>::Partition(Node* left, Node* right, T cmp)
{
	// ��l(�s�{�b�g)
	auto pivotValue = right->m_data;

	Node* i = left->m_prev;

	// �s�{�b�g����ɑ召�̗v�f�ɕ�����
	for (Node* j = left; j != right; j = j->m_next)
	{
		if (cmp(j->m_data, pivotValue))
		{
			i = (i == nullptr) ? left : i->m_next;
			Swap(i, j);
		}
	}

	i = (i == nullptr) ? left : i->m_next;
	Swap(i, right);

	// ���������I�����ʒu�̃s�{�b�g��Ԃ�
	return i;
}




//===============================================================
/*�R���X�g�C�e���[�^*/

// ���������R���X�g���N�^
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator() : m_Node(nullptr), m_List(nullptr) {}

// �����t���R���X�g���N�^
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(Node * node, const DoublyLinkedList* list) : m_Node(node), m_List(list) {}

// �R�s�[�R���X�g���N�^
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(const ConstIterator& it) : m_Node(it.m_Node), m_List(it.m_List) {}

// �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(�O�u)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator--()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode->m_next);
	m_Node = m_Node->m_prev;
	return *this;
}

// �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(��u)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::ConstIterator::operator--(int)
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode->m_next);
	ConstIterator ci = *this;
	m_Node = m_Node->m_prev;
	return ci;
}

// �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(�O�u)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator++()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	m_Node = m_Node->m_next;
	return *this;
}

// �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(��u)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::ConstIterator::operator++(int)
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	ConstIterator ci = *this;
	m_Node = m_Node->m_next;
	return ci;
}

// �C�e���[�^�̎w���v�f���擾����(const)
template<typename DATA>
inline const DATA DoublyLinkedList<DATA>::ConstIterator::operator*() const
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	return this->m_Node->m_data;
}

// ������s��
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator=(const ConstIterator & it)
{
	m_Node = it.m_Node;
	return *this;
}

// ���ꂩ��r����
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator==(const ConstIterator & it)
{
	return (m_Node == it.m_Node);
}

// �قȂ邩��r����
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator!=(const ConstIterator & it)
{
	return (m_Node != it.m_Node);
}

//===============================================================
/*�C�e���[�^*/
// ���������R���X�g���N�^
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator() : ConstIterator() {}

// �����t���R���X�g���N�^
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator(Node * node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

// �C�e���[�^�̎w���v�f���擾����(��const)
template<typename DATA>
inline DATA & DoublyLinkedList<DATA>::Iterator::operator*()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != this->m_List->m_DummyNode);
	return this->m_Node->m_data;
}