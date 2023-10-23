/**
* @file		doublyLinkedList.inl
* @brief	双方向リストクラス実装
* @author	村上輝
* @date		2023/10/20/12:00
* @details  課題1_4「クイックソート」
*/

#pragma once

#include <assert.h>
#include "doublyLinkedList.h"

//===============================================================
/*双方向リストクラス*/


// 双方向リストクラスのコンストラクタ
template<typename DATA>
inline DoublyLinkedList<DATA>::DoublyLinkedList() : m_DataNum(0)
{
	m_DummyNode = new Node();
	m_DummyNode->m_next = m_DummyNode;
	m_DummyNode->m_prev = m_DummyNode;
}

// 双方向リストクラスのデストラクタ
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

// データ数の取得
template<typename DATA>
inline int DoublyLinkedList<DATA>::GetDataNum() const
{
	return m_DataNum;
}

// データの挿入
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Insert(ConstIterator & it, const DATA & data)
{
	if (it.m_List != this) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn

	Node* newNode = new Node(data); // 新ノード

	Node* itNode = it.m_Node; // イテレータの指すノード

	// 新ノードの前ノードをイテレータの指す前ノードに。
	newNode->m_prev = itNode->m_prev;

	// 新ノードの次ノードをイテレータの指すノードに。
	newNode->m_next = itNode;

	// イテレータの指すノードの前ノードの次のノードに新ノードを格納
	// (イテレータノードと前ノードの間に格納)
	itNode->m_prev->m_next = newNode;

	// イテレータの指すノードの前ノードに新ノードを格納、これでデータが繋がる
	itNode->m_prev = newNode;

	// データ数を増やす
	m_DataNum++;

	return true;
}

// データの追加
template<typename DATA>
inline void DoublyLinkedList<DATA>::PushBack(const DATA & data)
{
	DoublyLinkedList<DATA>::ConstIterator endIt = end();
	Insert(endIt, data);
}

// データの削除
template<typename DATA>
inline bool DoublyLinkedList<DATA>::Remove(ConstIterator & it)
{
	Node* itNode = it.m_Node; // イテレータの指すノード
	if (m_DataNum == 0) return false;
	if (itNode == m_DummyNode) return false;
	if (it.m_List != this) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn

	itNode->m_prev->m_next = itNode->m_next;
	itNode->m_next->m_prev = itNode->m_prev;

	delete itNode;
	m_DataNum--;
	return true;
}

// 先頭イテレータ取得
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::begin()
{
	return Iterator(m_DummyNode->m_next, this);
}

// 先頭コンストイテレータ取得
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::begin() const
{
	return ConstIterator(m_DummyNode->m_next, this);
}

// 末尾イテレータ取得
template<typename DATA>
inline typename DoublyLinkedList<DATA>::Iterator DoublyLinkedList<DATA>::end()
{
	return Iterator(m_DummyNode, this);
}

// 末尾コンストイテレータ取得
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::end() const
{
	return ConstIterator(m_DummyNode, this);
}

// クイックソート
// クイックソートのアルゴリズム、コードを参考にしたサイト https://daeudaeu.com/quicksort/
// 比較関数、ラムダ式について参考にしたサイト https://qiita.com/threecups/items/aa1923a9922dc0a7abfe
template<typename DATA>
inline void DoublyLinkedList<DATA>::QuickSort(bool cmp(const DATA&, const DATA&))
{
	// 要素がひとつ以下だったら終了
	if (m_DataNum <= 1) return;

	DoublyLinkedList<DATA>::Iterator beginIt = begin();
	DoublyLinkedList<DATA>::Iterator endIt = end();

	QuickSortProcess(beginIt, --endIt, cmp);
}

// ノードの持つデータを入れ替える関数
template<typename DATA>
inline void DoublyLinkedList<DATA>::Swap(Node* node1, Node* node2)
{
	{
		DATA temp = node1->m_data;

		node1->m_data = node2->m_data;

		node2->m_data = temp;
	}

	{
		//node1->m_prev->m_next = node2;
		//node1->m_next->m_prev = node2;
		//node2->m_prev->m_next = node1;
		//node2->m_next->m_prev = node1;

		//Node* tempPrev = node1->m_prev;
		//Node* tempNext = node1->m_next;

		//node1->m_prev = node2->m_prev;
		//node1->m_next = node2->m_next;
		//node2->m_prev = tempPrev;
		//node2->m_next = tempNext;
	}
}

// 探索が終わったかを判別する関数
template<typename DATA>
inline const bool DoublyLinkedList<DATA>::SearchFinished(Node * left, Node * right) const
{
	Node* i = left;
	Node* j = right;

	while (i != m_DummyNode)
	{
		if (i == right)
		{
			return true;
		}
		else
		{
			i = i->m_prev;
		}
	}

	return false;
}

// クイックソートの内部処理
template<typename DATA>
inline void DoublyLinkedList<DATA>::QuickSortProcess(ConstIterator & left, ConstIterator & right, bool cmp(const DATA&, const DATA&))
{
	// 入れ替え処理終了
	if (left.m_Node == right.m_Node->m_next)return;
	if (left == right)return;

	Node* i = left.m_Node;
	Node* j = right.m_Node;

	// 基準値(ピボット)
	DATA pivot = left.m_Node->m_data;

	// pivot以下のデータを左に、pivot以上のデータを右に集める
	while (1)
	{
		// 左側から探索(ピボット以上のデータを見つけたらor右端に達したら終了)
		while (cmp(i->m_data, pivot))
		{
			if (i == right.m_Node) break;
			i = i->m_next;
		}

		// 右側から探索(ピボット以下のデータを見つけたらor左端に達したら終了)
		while (!cmp(j->m_data, pivot))
		{
			if (j == left.m_Node) break;
			j = j->m_prev;
		}

		// iがjよりも右にあったらループからぬける
		if (SearchFinished(i, j)) break;

		// 入れ替える
		Swap(i, j);

		// 再度探索開始
		i = i->m_next;
		j = j->m_prev;
	}

	ConstIterator it = ConstIterator(i->m_prev, this);
	ConstIterator it2 = ConstIterator(j->m_next, this);
	QuickSortProcess(left, it, cmp);
	QuickSortProcess(it2, right, cmp);
}




//===============================================================
/*コンストイテレータ*/

// 引数無しコンストラクタ
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator() : m_Node(nullptr), m_List(nullptr) {}

// 引数付きコンストラクタ
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(Node * node, const DoublyLinkedList* list) : m_Node(node), m_List(list) {}

// コピーコンストラクタ
template<typename DATA>
inline DoublyLinkedList<DATA>::ConstIterator::ConstIterator(const ConstIterator& it) : m_Node(it.m_Node), m_List(it.m_List) {}

// イテレータの先頭に向かってひとつ進める(前置)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator--()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode->m_next);
	m_Node = m_Node->m_prev;
	return *this;
}

// イテレータの先頭に向かってひとつ進める(後置)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::ConstIterator::operator--(int)
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode->m_next);
	ConstIterator ci = *this;
	m_Node = m_Node->m_prev;
	return ci;
}

// イテレータの末尾に向かってひとつ進める(前置)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator++()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	m_Node = m_Node->m_next;
	return *this;
}

// イテレータの末尾に向かってひとつ進める(後置)
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator DoublyLinkedList<DATA>::ConstIterator::operator++(int)
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	ConstIterator ci = *this;
	m_Node = m_Node->m_next;
	return ci;
}

// イテレータの指す要素を取得する(const)
template<typename DATA>
inline const DATA DoublyLinkedList<DATA>::ConstIterator::operator*() const
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != m_List->m_DummyNode);
	return this->m_Node->m_data;
}

// 代入を行う
template<typename DATA>
inline typename DoublyLinkedList<DATA>::ConstIterator& DoublyLinkedList<DATA>::ConstIterator::operator=(const ConstIterator & it)
{
	m_Node = it.m_Node;
	return *this;
}

// 同一か比較する
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator==(const ConstIterator & it)
{
	return (m_Node == it.m_Node);
}

// 異なるか比較する
template<typename DATA>
inline bool DoublyLinkedList<DATA>::ConstIterator::operator!=(const ConstIterator & it)
{
	return (m_Node != it.m_Node);
}

//===============================================================
/*イテレータ*/
// 引数無しコンストラクタ
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator() : ConstIterator() {}

// 引数付きコンストラクタ
template<typename DATA>
inline DoublyLinkedList<DATA>::Iterator::Iterator(Node * node, const DoublyLinkedList* list) : ConstIterator(node, list) {}

// イテレータの指す要素を取得する(非const)
template<typename DATA>
inline DATA & DoublyLinkedList<DATA>::Iterator::operator*()
{
	assert(this->m_Node != nullptr);
	assert(this->m_Node != this->m_List->m_DummyNode);
	return this->m_Node->m_data;
}
