#include "pch.h"

CLevelupEvent::CLevelupEvent(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, TEXTURE)
{
}

CLevelupEvent::~CLevelupEvent()
{
}

void CLevelupEvent::Update(DWORD elapsed)
{
	if (timeGetTime() - m_Timer > m_ViewTime)
	{
		m_isLive = false;
	}
}

void CLevelupEvent::Control(CInput* Input)
{
}

void CLevelupEvent::Render()
{
	if (m_isLive)
		m_Sprite->DrawCenter(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
