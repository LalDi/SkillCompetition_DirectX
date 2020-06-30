#include "pch.h"

CLevelUI::CLevelUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, cPlayer* player)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, UI)
{
	Player = player;

	m_Sprites[0] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/UI/UI_LV1.png");
	m_Sprites[1] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/UI/UI_LV2.png");
	m_Sprites[2] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/UI/UI_LV3.png");
	m_Sprites[3] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/UI/UI_LV4.png");
	m_Sprites[4] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/UI/UI_LV5.png");
}

CLevelUI::~CLevelUI()
{
}

void CLevelUI::Update(DWORD elapsed)
{
	m_NowLevel = Player->GetLevel();
	switch (m_NowLevel)
	{
	case 1: m_Sprite = m_Sprites[0]; break;
	case 2: m_Sprite = m_Sprites[1]; break;
	case 3: m_Sprite = m_Sprites[2]; break;
	case 4: m_Sprite = m_Sprites[3]; break;
	case 5: m_Sprite = m_Sprites[4]; break;
	default:
		break;
	}
}

void CLevelUI::Control(CInput* Input)
{
}

void CLevelUI::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
