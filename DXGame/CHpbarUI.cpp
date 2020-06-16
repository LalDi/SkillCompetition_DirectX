#include "pch.h"

CHpbarUI::CHpbarUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, cPlayer* player)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, UI)
{
	Player = player;
	//m_Scale = { 0.4f, 0.4f };
	
}

CHpbarUI::~CHpbarUI()
{
}

void CHpbarUI::Update(DWORD elapsed)
{
	m_NowHp = Player->GetHp();
	m_MaxHp = Player->GetMaxHp();
	if (m_NowHp == m_MaxHp && Player->m_isLive)
		m_Sprite->m_sprWidth = m_Sprite->m_imageWidth;
	else if (m_NowHp > 0)
		m_Sprite->m_sprWidth = ((float)m_NowHp / (float)m_MaxHp) * m_Sprite->m_imageWidth;
	else
		m_Sprite->m_sprWidth = 1;
}

void CHpbarUI::Control(CInput* Input)
{
}

void CHpbarUI::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
