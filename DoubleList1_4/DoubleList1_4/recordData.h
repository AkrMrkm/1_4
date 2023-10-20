/**
* @file		recordData.h
* @brief    ���уf�[�^�\����
* @author   ����P
* @date     2023/10/20/11:00
* @details  �ۑ�1_4�u�N�C�b�N�\�[�g�̎����v\n
*			�ۑ�Ń��X�g�Ɋi�[���鐬�уf�[�^�̍\���̂ł�\n
*/

#pragma once

/**
* @brief ���уf�[�^�\����
*/
struct RecordData
{
	//! �X�R�A
	int m_score;

	//! ���O
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