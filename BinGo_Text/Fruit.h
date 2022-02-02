#pragma once

class CFruit
{
public:
	CFruit(const char* Name);
	~CFruit();
	const char* m_Name;

public:
	static const int m_N = 25;
	const char* GetName();
	
};

