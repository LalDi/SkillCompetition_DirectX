#include "pch.h"

CFirstEnemy::CFirstEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CEnemy(sFileName, Pos, sprWidth, sprHeight)
{
	m_Hp = 70;
	m_AttackSpeed = 2;
	m_Damage = 4;
	m_GiveExp = 15;
}

CFirstEnemy::~CFirstEnemy()
{
}

void CFirstEnemy::Update(DWORD elapsed)
{
	CEnemy::Update(elapsed);
}

void CFirstEnemy::Control(CInput* Input)
{
}

void CFirstEnemy::Render()
{
	CEnemy::Render();
}
