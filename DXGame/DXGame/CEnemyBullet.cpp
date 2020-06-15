#include "pch.h"

CEnemyBullet::CEnemyBullet(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int Angle, int Damage)
	:CBullet(sFileName, Pos, sprWidth, sprHeight, Angle, Damage)
{
	m_Speed = 300;
	b_PlayerBullet = false;
}

CEnemyBullet::~CEnemyBullet()
{
}

void CEnemyBullet::Update(DWORD elapsed)
{
	CBullet::Update(elapsed);

	m_Pos.y += m_Speed * elapsed / 1000.f;
}

void CEnemyBullet::Control(CInput* Input)
{
}

void CEnemyBullet::Render()
{
	CBullet::Render();
}
