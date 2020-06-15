#include "pch.h"

CScroolMap::CScroolMap(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, TEXTURE)
{
}

CScroolMap::~CScroolMap()
{
}

void CScroolMap::Update(DWORD elapsed)
{
	m_Pos.y += 5.f;
	if (m_Pos.y > WinSizeY)
		m_Pos.y -= WinSizeY * 2;
}

void CScroolMap::Control(CInput* Input)
{
}

void CScroolMap::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 0);
}
