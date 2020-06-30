#include "pch.h"

CExpbarUI::CExpbarUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, cPlayer* player)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, UI)
{
	Player = player;
	//m_Scale = { 0.6f, 0.6f };
}

CExpbarUI::~CExpbarUI()
{
}

void CExpbarUI::Update(DWORD elapsed)
{
	m_NowExp = Player->GetExp();
	if (m_NowExp == PlayerLevel(m_NowExp) && Player->m_isLive)
		m_Sprite->m_sprWidth = m_Sprite->m_imageWidth;
	else if (m_NowExp > 0)
		m_Sprite->m_sprWidth = ((float)m_NowExp / (float)PlayerLevel(Player->GetLevel())) * m_Sprite->m_imageWidth;
	else
		m_Sprite->m_sprWidth = 0;
}

void CExpbarUI::Control(CInput* Input)
{
}

void CExpbarUI::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
