#include "pch.h"

CStatusFrameUI::CStatusFrameUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, UI)
{
	//m_Scale = { 0.4f, 0.4f };
}

CStatusFrameUI::~CStatusFrameUI()
{
}

void CStatusFrameUI::Update(DWORD elapsed)
{
}

void CStatusFrameUI::Control(CInput* Input)
{
}

void CStatusFrameUI::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
