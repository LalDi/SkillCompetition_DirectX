#include "pch.h"
#include "cPlayer.h"

cPlayer::cPlayer(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, PLAYER)
{
	m_Radius = ((sprWidth * m_Scale.x >= sprHeight * m_Scale.y) ? sprWidth * m_Scale.x : sprHeight * m_Scale.y) / 2;

	m_Speed = 5.f;
	m_Angle = 0;
	m_FireStart = 0;
	b_Fire = false;
	b_ShootMode = true;
	
	m_Level = 1;
	m_Exp = 0;
	m_MaxHp = 100;
	m_Hp = m_MaxHp;
	m_Damage = 10;
	m_AttackSpeed = 10;
}

cPlayer::~cPlayer()
{
}

void cPlayer::Update(DWORD elapsed)
{
	m_Delay = 1000 / m_AttackSpeed;

	if (m_Exp >= 100)
	{
		m_MaxHp *= 1.2f;
		m_Damage *= 1.2f;
		m_AttackSpeed *= 1.2f;
		m_Hp = m_MaxHp;
		m_Exp = 0;
	}

	if (m_Hp <= 0)
		m_isLive = false;
	CGameObject::Update(elapsed);
}

void cPlayer::Control(CInput* Input)
{
	if (Input->KeyPress(VK_W) && m_Pos.y >= 0)
		m_Pos.y -= m_Speed;
	if (Input->KeyPress(VK_A) && m_Pos.x >= 0)
		m_Pos.x -= m_Speed;
	if (Input->KeyPress(VK_S) && m_Pos.y <= WinSizeY)
		m_Pos.y += m_Speed;
	if (Input->KeyPress(VK_D) && m_Pos.x <= WinSizeX)
		m_Pos.x += m_Speed;

	POINT Mouse = Input->GetMousePos();
	POINT Vector = { Mouse.x - m_Pos.x, Mouse.y - m_Pos.y };
	m_Angle = ToDegree(atan2(Vector.y, Vector.x)) + 90;

	if (Input->BtnDown(0) || Input->BtnPress(0) && timeGetTime() - m_FireStart > m_Delay)
	{
		b_Fire = true;
		m_FireStart = timeGetTime();
	}
	else
		b_Fire = false;

	if (Input->BtnDown(1))
	{
		if (b_ShootMode)
		{
			m_Damage /= 2;
			m_AttackSpeed /= 2;
			b_ShootMode = false;
		}
		else
		{
			m_Damage *= 2;
			m_AttackSpeed *= 2;
			b_ShootMode = true;
		}
	}
}

void cPlayer::Render()
{
	if (m_isLive)
		m_Sprite->DrawCenter(&m_rTiled, m_Pos, m_Scale, &m_Pos, m_Angle);
}

CGameObject* cPlayer::Fire(float Angle)
{
	CGameObject* temp = new CPlayerBullet(L"./Images/Bullet.png", m_Pos, 8, 25, Angle, m_Damage);
	b_Fire = false;
	return temp;
}
