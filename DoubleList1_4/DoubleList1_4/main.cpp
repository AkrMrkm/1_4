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

	{
		// �����\�[�g
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
			DoublyLinkedList<RecordData>::Iterator endIt = list.end();

			auto cmp = [](RecordData a, RecordData b) { return a < b; }; // ����

			list.QuickSort(beginIt, endIt, cmp);
		}

		std::cout << "[����]" << std::endl;

		// ���X�g���i�[�������ŕ\��
		for (const RecordData& data : list)
		{
			std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
		}
	}

	std::cout << "\n ������x�L�[�������ƍ~���Ń\�[�g���܂��B" << std::endl;
	getchar();

	{
		// �~���\�[�g
		{
			DoublyLinkedList<RecordData>::Iterator beginIt = list.begin();
			DoublyLinkedList<RecordData>::Iterator endIt = list.end();

			auto cmp = [](RecordData a, RecordData b) { return a > b; }; // �~��

			list.QuickSort(beginIt, endIt, cmp);
		}

		std::cout << "[�~��]" << std::endl;

		// ���X�g���i�[�������ŕ\��
		for (const RecordData& data : list)
		{
			std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
		}
	}

	getchar();

	return 0;
}