#include "pch.h"

CFramemask::CFramemask(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, UI)
{
}

CFramemask::~CFramemask()
{
}

void CFramemask::Update(DWORD elapsed)
{
}

void CFramemask::Control(CInput* Input)
{
}

void CFramemask::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
