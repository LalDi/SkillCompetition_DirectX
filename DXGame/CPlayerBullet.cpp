#include "pch.h"

CPlayerBullet::CPlayerBullet(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int Angle, int Damage)
	:CBullet(sFileName, Pos, sprWidth, sprHeight, Angle, Damage)
{
	b_PlayerBullet = true;
}

CPlayerBullet::~CPlayerBullet()
{
}

void CPlayerBullet::Update(DWORD elapsed)
{
	CBullet::Update(elapsed);

	m_Pos.x += m_Speed * sin(ToRadian(m_Angle)) * elapsed / 1000.f;
	m_Pos.y -= m_Speed * cos(ToRadian(m_Angle)) * elapsed / 1000.f;
}

void CPlayerBullet::Control(CInput* Input)
{
}

void CPlayerBullet::Render()
{
	CBullet::Render();
}
