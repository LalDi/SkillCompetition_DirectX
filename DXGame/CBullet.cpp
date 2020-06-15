#include "pch.h"

CBullet::CBullet(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int Angle, int Damage)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, BULLET)
{
	m_Speed = 700.f;
	m_Angle = Angle;
	m_Damage = Damage;
}

CBullet::~CBullet()
{
}

void CBullet::Update(DWORD elapsed)
{
	CGameObject::Update(elapsed);
	if (OutMap())
		m_isLive = false;
}

void CBullet::Control(CInput* Input)
{
}

void CBullet::Render()
{
	if (m_isLive)
		m_Sprite->DrawCenter(&m_rTiled, m_Pos, m_Scale, &m_Pos, m_Angle);
}

bool CBullet::OutMap()
{
	bool temp;
	temp = m_Pos.x < -100 || m_Pos.x > WinSizeX + 100 || m_Pos.y < -100 || m_Pos.y > WinSizeY + 100;
	return temp;
}
