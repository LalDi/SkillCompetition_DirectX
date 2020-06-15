#include "pch.h"

CAsteroidEnemy::CAsteroidEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CEnemy(sFileName, Pos, sprWidth, sprHeight)
{
	m_Speed = 1000;
	m_Angle = 0;

	m_Damage = 20;
}

CAsteroidEnemy::~CAsteroidEnemy()
{
}

void CAsteroidEnemy::Update(DWORD elapsed)
{
	int temp = rand() % 5;
	m_Hp = 9999;
	m_Angle += temp;
	CEnemy::Update(elapsed);
}

void CAsteroidEnemy::Control(CInput* Input)
{
}

void CAsteroidEnemy::Render()
{
	if (m_isLive)
		m_Sprite->DrawCenter(&m_rTiled, m_Pos, m_Scale, &m_Pos, m_Angle);
}
