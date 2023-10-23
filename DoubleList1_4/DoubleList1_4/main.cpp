/**
* @file		main.cpp
* @brief	�o�������X�g�N���X
* @author	����P
* @date		2023/10/20/11:00
* @details  �ۑ�1_4�u�N�C�b�N�\�[�g�v
*/

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"
#include "recordData.h"

// ���O�ŏ���
bool NameAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_name < b.m_name; };

// ���O�ō~��
bool NameDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_name > b.m_name; };

// �X�R�A�ŏ���
bool ScoreAscendingOrder(const RecordData& a, const RecordData& b) { return a.m_score < b.m_score; };

// �X�R�A�ō~��
bool ScoreDescendingOrder(const RecordData& a, const RecordData& b) { return a.m_score > b.m_score; };

int main()
{
	//�t�@�C���ǂݍ���
	std::ifstream inputFile("Scores.txt");

	// �t�@�C�����J���Ȃ�������I��
	if (!inputFile.is_open())
	{
		std::cerr << "�t�@�C�����J���܂���B" << std::endl;
		getchar();
		return 0;
	}

	DoublyLinkedList<RecordData> list;

	// �t�@�C������ǂݍ��񂾒l���i�[����ϐ�
	int score;
	std::string name;

	// �t�@�C������f�[�^��ǂݍ���Ń��X�g�ɒǉ�
	while (inputFile >> score >> name)
	{
		RecordData data = { score,name };
		list.PushBack(data);
	}

	// �t�@�C�������
	inputFile.close();

	// �\�[�g
	{
		list.QuickSort(ScoreAscendingOrder);
		//list.QuickSort(DescendingOrder);
	}

	// ���X�g��\��
	for (const RecordData& data : list)
	{
		std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
	}

	getchar();

	return 0;
}
