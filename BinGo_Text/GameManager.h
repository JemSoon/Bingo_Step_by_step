#pragma once
#include "Fruit.h"
class CGameManager
{
private:
	CGameManager();
	~CGameManager();
	

public:
	static CGameManager* m_pInst;
	static CGameManager* GetInst();
	static void DestroyInst();

public:
	static const int m_N = 25;
	int m_NN;
	int arr[m_N];
	char* input;
	int bingo;

public:
	void Shuffle();
	void Render();
	void Input();
	void BingoCount();
	void Minus1();
	void run();

	CFruit fruit[m_N];
};

