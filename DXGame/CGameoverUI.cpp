#include "pch.h"

CGameoverUI::CGameoverUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, UI)
{
}

CGameoverUI::~CGameoverUI()
{
}

void CGameoverUI::Update(DWORD elapsed)
{
}

void CGameoverUI::Control(CInput* Input)
{
}

void CGameoverUI::Render()
{
	m_Sprite->DrawCenter(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
