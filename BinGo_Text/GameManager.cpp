#include "GameManager.h"
#include <iostream>
#include <time.h>


CGameManager* CGameManager::m_pInst = nullptr;

CGameManager::CGameManager() :
	arr{}, input(0), m_NN((int)sqrt(m_N)), bingo(0), fruit
{"하나","둘", "셋", "넷", "다섯", "여섯", "일곱", "여덟", "아홉", "열", 
"열하나", "열둘", "열셋", "열넷", "열다섯", "열여섯", "열일곱", "열여덟", "열아홉", "스물", 
"스물하나", "스물둘", "스물셋", "스물넷", "스물다섯"}
{

}

CGameManager::~CGameManager()
{

}

CGameManager* CGameManager::GetInst()
{
	if (!m_pInst)
	{
		m_pInst = new CGameManager;
	}
	return m_pInst;
}

void CGameManager::DestroyInst()
{
	if (!m_pInst)
	{
		return;
	}
	delete m_pInst;
	m_pInst = nullptr;
}

void CGameManager::Shuffle()
{
	srand((unsigned int)time(0));

	for (int i = 0; i < m_N; ++i)
	{
		arr[i] = rand() % 25;

		for (int j = 0; j < i; ++j)
		{
			if (arr[i] == arr[j])
			{
				--i;
			}
		}
	}
}

void CGameManager::Render()
{
	std::cout << "빙고 : " << bingo << std::endl;

	for (int i = 0; i < m_N; ++i)
	{
		

		if ((i + 1) % 5 == 0)
		{
			std::cout << fruit[arr[i]].GetName() << std::endl;
		}
		else
		{
			std::cout << fruit[arr[i]].GetName() << "\t";
		}
	}
}

void CGameManager::Input()
{
	std::cin >> input;
	/*if (input < 0 || input>25)
	{
		std::cout << "올바른 범위의 수를 입력하세요\t";
		system("pause");
		system("cls");
	}*/
	system("cls");
}

void CGameManager::BingoCount()
{
	bingo = 0;

	for (int i = 0; i < m_NN; ++i)
	{
		for (int j = 0; j < m_NN; ++j)
		{
			if (arr[i * m_NN + j] != -1)
			{
				break;
			}
			if (j==4)
			{
				++bingo;
			}
		}
	}
}

void CGameManager::Minus1()
{
	for (int i = 0; i < m_N; ++i)
	{
		if (fruit[arr[i]].GetName() == input)
		{
			fruit[arr[i]] = " - 1";//몬가 안댐
		}
	}
}

void CGameManager::run()
{
	Shuffle();

	while (1)
	{
		Render();
		
		Input();

		Minus1();

		BingoCount();
	}
}