#include "pch.h"

CExplosionEvent::CExplosionEvent(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, bool IsEnemy)
	:CGameObject(sFileName, Pos, sprWidth, sprHeight, TEXTURE)
{
	if (IsEnemy)
		m_Scale = { 1,1 };
	else
		m_Scale = { 2,2 };

	m_Sprites[0] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion1.png");
	m_Sprites[1] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion2.png");
	m_Sprites[2] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion3.png");
	m_Sprites[3] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion4.png");
	m_Sprites[4] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion5.png");
	m_Sprites[5] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion6.png");
	m_Sprites[6] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion7.png");
	m_Sprites[7] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion8.png");
	m_Sprites[8] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion9.png");
	m_Sprites[9] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion10.png");
	m_Sprites[10] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion11.png");
	m_Sprites[11] = CGameManager::GetSpriteManager()->GetSprite(L"./Images/Explosion/explosion12.png");
}

CExplosionEvent::~CExplosionEvent()
{
}

void CExplosionEvent::Update(DWORD elapsed)
{
	if (timeGetTime() - m_Timer > 50)
	{
		switch (m_ImageCounter)
		{
		case 0:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 1:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 2:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 3:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 4:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 5:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 6:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 7:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 8:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 9:	m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 10:m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 11:m_Sprite = m_Sprites[m_ImageCounter];	m_Timer = timeGetTime();	break;
		case 12:m_isLive = false;
		}
		m_ImageCounter++;
	}
}

void CExplosionEvent::Control(CInput* Input)
{
}

void CExplosionEvent::Render()
{
	if (m_isLive)
		m_Sprite->DrawCenter(&m_rTiled, m_Pos, m_Scale, &m_Pos);
}
