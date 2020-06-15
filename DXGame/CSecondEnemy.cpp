#include "pch.h"

CSecondEnemy::CSecondEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CEnemy(sFileName, Pos, sprWidth, sprHeight)
{
	m_Hp = 50;
	m_AttackSpeed = 4;
	m_Damage = 2;
	m_GiveExp = 10;
}

CSecondEnemy::~CSecondEnemy()
{
}

void CSecondEnemy::Update(DWORD elapsed)
{
	CEnemy::Update(elapsed);
}

void CSecondEnemy::Control(CInput* Input)
{
}

void CSecondEnemy::Render()
{
	CEnemy::Render();
}
