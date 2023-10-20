/**
* @file		recordData.h
* @brief    成績データ構造体
* @author   村上輝
* @date     2023/10/20/11:00
* @details  課題1_4「クイックソートの実装」\n
*			課題でリストに格納する成績データの構造体です\n
*/

#pragma once

/**
* @brief 成績データ構造体
*/
struct RecordData
{
	//! スコア
	int m_score;

	//! 名前
	std::string m_name;

	bool operator<(const RecordData& other) const
	{
		return (m_score	< other.m_score) ||
			(m_score == other.m_score && m_name < other.m_name);
	}

	bool operator>(const RecordData& other) const
	{
		return (m_score	> other.m_score) ||
			(m_score == other.m_score && m_name > other.m_name);
	}

	bool operator==(const RecordData& other) const
	{
		return (m_score == other.m_score);
	}
};