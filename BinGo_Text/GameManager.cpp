#include "GameManager.h"
#include <iostream>
#include <time.h>

CGameManager* CGameManager::m_pInst = nullptr;

CGameManager::CGameManager() :
	arr{}, input(0), m_NN((int)sqrt(m_N)), bingo(0)
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
		arr[i] = rand() % 25 + 1;

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
			std::cout <<arr[i]<< std::endl;
		}
		else
		{
			std::cout << arr[i]<<"\t";
		}
	}
}

void CGameManager::Input()
{
	std::cin >> input;
	if (input < 0 || input>25)
	{
		std::cout << "올바른 범위의 수를 입력하세요\t";
		system("pause");
		system("cls");
	}
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
		if (arr[i] == input)
		{
			arr[i] = -1;
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