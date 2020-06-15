#include "pch.h"

CEnemy::CEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, ENEMY)
{
	m_Speed = 30;
}

CEnemy::~CEnemy()
{
}

void CEnemy::Update(DWORD elapsed)
{
	if (OutMap() || m_Hp <= 0)
		m_isLive = false;
	m_Pos.y += m_Speed * elapsed / 1000.f;
	CGameObject::Update(elapsed);
}

void CEnemy::Control(CInput* Input)
{
}

void CEnemy::Render()
{
	if (m_isLive)
		m_Sprite->DrawCenter(&m_rTiled, m_Pos, m_Scale, &m_Pos, 180);
}

bool CEnemy::OutMap()
{
	bool temp;
	temp = m_Pos.x < -100 || m_Pos.x > WinSizeX + 100 || m_Pos.y < -100 || m_Pos.y > WinSizeY + 100;
	return temp;
}

bool CEnemy::IsFire()
{
	if (timeGetTime() - m_bulletTimer > (1000 / m_AttackSpeed)) 
	{
		m_bulletTimer = timeGetTime();
		return true;
	}
	return false;
}

