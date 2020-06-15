#include "pch.h"

CInput* CGameManager::m_Input = NULL;
CGraphics* CGameManager::m_Gfx = NULL;
CSpriteManager* CGameManager::m_ImageManager = NULL;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init(CInput* Input, CGraphics* gfx, CSpriteManager* ImageMgr)
{
	m_Input = Input;
	m_Gfx = gfx;
	m_ImageManager = ImageMgr;
}
