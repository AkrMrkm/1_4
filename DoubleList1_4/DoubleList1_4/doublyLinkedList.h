/**
* @file		doublyLinkedList.h
* @brief	双方向リストクラスヘッダー
* @author	村上輝
* @date		2023/10/20/12:00
* @details  課題1_4「クイックソート」
*/

#pragma once

/**
* @brief  双方向リストクラス
* @tparam DATA リストが格納するデータ
*/
template<typename DATA>
class DoublyLinkedList
{
private:
	/**
	* @brief ノード
	*/
	struct Node
	{
		//! 前ノード
		Node* m_prev;

		//! 次ノード
		Node* m_next;

		//! データ
		DATA m_data;

		/**
		* @brief 引数無しコンストラクタ
		*/
		Node() : m_prev(nullptr), m_next(nullptr), m_data() {}

		/**
		* @brief     引数付きコンストラクタ
		* @param[in] data 要素が持つデータ
		*/
		explicit Node(const DATA data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

	//! ダミーノード
	Node* m_DummyNode;

	//! データ数
	int m_DataNum;

public:

	/**
	* @brief   コンストイテレータクラス
	* @details 双方向リストクラスのインナークラス
	*/
	class ConstIterator
	{
	private:
		//! 双方向リストクラスをfriend指定
		friend class DoublyLinkedList;

		//! ノードへのポインタ
		Node* m_Node;

		//! リストのポインタ
		const DoublyLinkedList* m_List;

	public:

		/**
		* @brief 引数無しコンストラクタ
		*/
		inline ConstIterator();

		/**
		* @brief     引数付きコンストラクタ
		* @param[in] node イテレータの指す要素
		* @param[in] list リストの参照
		*/
		inline ConstIterator(Node* node, const DoublyLinkedList* list);

		/**
		* @brief   イテレータの先頭に向かってひとつ進める(前置)
		* @return  先頭にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらor先頭イテレータであったらassert
		*/
		inline ConstIterator& operator--();

		/**
		* @brief	イテレータの先頭に向かってひとつ進める(後置)
		* @return	先頭にひとつ進めたイテレータを返す
		* @details	ノードの参照が無かったらor先頭イテレータであったらassert
		*/
		inline ConstIterator operator--(int);

		/**
		* @brief	イテレータの末尾に向かってひとつ進める(前置)
		* @return	末尾にひとつ進めたイテレータを返す
		* @details	ノードの参照が無かったらor末尾イテレータであったらassert
		*/
		inline ConstIterator& operator++();

		/**
		* @brief	イテレータの末尾に向かってひとつ進める(後置)
		* @return	末尾にひとつ進めたイテレータを返す
		* @details	ノードの参照が無かったらor末尾イテレータであったらassert
		*/
		inline ConstIterator operator++(int);

		/**
		* @brief	イテレータの指す要素を取得する(const)
		* @return	イテレータの指すデータを返す
		* @details	ノードの参照が無かったらor末尾イテレータであったらassert
		*/
		inline const DATA operator*() const;

		/**
		* @brief		コピーコンストラクタ
		* @param[in]	it コピー元のコンストイテレータ
		*/
		inline ConstIterator(const ConstIterator& it);

		/**
		* @brief		代入を行う
		* @param[in]	it 代入するイテレータ
		* @details		イテレータのノードを代入する
		*/
		inline ConstIterator& operator=(const ConstIterator& it);

		/**
		* @brief		同一か比較する
		* @param[in]	it 同一か比較するイテレータ
		* @return		イテレータの指す要素が同一であればtrueを返す
		*/
		inline bool operator==(const ConstIterator& it);

		/**
		* @brief		異なるか比較する
		* @param[in]	it 異なるか比較するイテレータ
		* @return		イテレータの指す要素が異なればtrueを返す
		*/
		inline bool operator!=(const ConstIterator& it);
	};

	/**
	* @brief	イテレータクラス
	* @details	コンストイテレータクラスの派生クラス
	*/
	class Iterator : public ConstIterator
	{
	public:
		/**
		* @brief 引数無しコンストラクタ
		*/
		inline Iterator();

		/**
		* @brief		引数付きコンストラクタ
		* @param[in]	node イテレータの指す要素
		* @param[in]	list リストの参照
		*/
		inline explicit Iterator(Node* node, const DoublyLinkedList* list);

		/**
		* @brief	イテレータの指す要素を取得する(非const)
		* @return	イテレータの指す成績データを返す
		* @details	ノードの参照が無かったらor末尾イテレータであったらassert
		*/
		inline DATA& operator*();
	};

	/**
	* @brief	双方向リストクラスのコンストラクタ
	* @details	データ数、ダミーノードを初期化\n
	*			リストが空の場合、ダミーノードの前後はダミーノード自身を参照\n
	*/
	inline DoublyLinkedList();

	/**
	* @brief	双方向リストクラスのデストラクタ
	* @details  先頭から末尾までdelete
	*/
	virtual inline ~DoublyLinkedList();

	/**
	* @brief	 コピーコンストラクタ
	* @param[in] list コピー元の双方向リスト
	*/
	inline DoublyLinkedList(const DoublyLinkedList& list) = delete;

	/**
	* @brief  データ数の取得
	* @return リストのデータの総数を返す
	*/
	inline int GetDataNum() const;

	/**
	* @brief		データの挿入
	* @param[in]	it 挿入したい位置のイテレータ
	* @param[in]	data 挿入したい成績データ
	* @return		bool(挿入が成功すればtrue、失敗すればfalse)
	* @details		イテレータの指すノードの前に挿入する
	*/
	inline bool Insert(ConstIterator& it, const DATA& data);

	/**
	* @brief		データの追加
	* @param[in]	data 追加したい成績データ
	* @details		末尾にデータの追加
	*/
	inline void PushBack(const DATA& data);

	/**
	* @brief		データの削除
	* @param[in]	it 削除したい位置のイテレータ
	* @return		削除に失敗したらfalse、成功したらtrueを返す
	* @details		イテレータの指すノードを削除\n
	*				データ数が0、イテレータの指すノードが末尾イテレータ、別リストを指すイテレータであれば何も行わない\n
	*/
	inline bool Remove(ConstIterator& it);

	/**
	* @brief	先頭イテレータ取得
	* @return	先頭のイテレータを返す
	*/
	inline Iterator begin();

	/**
	* @brief	 先頭コンストイテレータ取得
	* @return	 先頭のコンストイテレータを返す
	*/
	inline ConstIterator begin() const;

	/**
	* @brief	 末尾イテレータ取得
	* @return	 末尾のイテレータを返す
	*/
	inline Iterator end();

	/**
	* @brief	末尾コンストイテレータ取得
	* @return	末尾のコンストイテレータを返す
	*/
	inline ConstIterator end() const;

	/**
	* @brief		クイックソート
	* @param[in]	leftIt  ソートを行う範囲の左端のイテレータ
	* @param[in]	rightIt ソートを行う範囲の右端のイテレータ
	* @param[in]	cmp		比較関数オブジェクト
	* @details		リストの要素を比較関数に応じて降順または昇順で整列させる
	*/
	template<typename T>
	inline void QuickSort(ConstIterator & left, ConstIterator & right, T cmp);

	private:
		/**
		* @brief		ノードの持つデータを入れ替える関数
		* @param[in]	node1 node2と入れ替えるノード
		* @param[in]	node2 node1と入れ替えるノード
		* @details		node1とnode2のデータを入れ替える
		*/
		inline void Swap(Node* node1, Node* node2);

		/**
		* @brief		基準値をもとに分割して入れ替えて基準値を返す関数
		* @param[in]	left ソートを行う範囲の左端のノード
		* @param[in]	right ソートを行う範囲の右端のノード
		* @param[in]	cmp		比較関数オブジェクト
		* @return		入れ替え処理が終わった後の位置のノードを返す
		* @details		与えられた範囲内の要素を基準値より小さい要素と大きい要素に分け、入れ替えが終わった時点での基準値を返す。
		*/
		template<typename T>
		inline Node* Partition(Node* left, Node* right, T cmp);
};

#include "doublyLinkedList.inl"
