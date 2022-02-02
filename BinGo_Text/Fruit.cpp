#include "Fruit.h"

CFruit::CFruit(const char* Name) : m_Name(Name)
{

}

CFruit::~CFruit()
{

}

const char* CFruit::GetName()
{
	return m_Name;
}

