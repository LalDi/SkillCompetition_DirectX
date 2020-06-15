#include "pch.h"

CSpriteManager::CSpriteManager()
{
}

CSpriteManager::~CSpriteManager()
{
	Destroy();
}

CSprite* CSpriteManager::GetSprite(LPCWSTR sFile)
{
	CSprite* Spr = m_SpriteMap[sFile];
	if (Spr == NULL)
		return LoadData(sFile);
	else
		return Spr;
}

CSprite* CSpriteManager::LoadData(LPCWSTR sFile)
{
	CSprite* Spr = new CSprite(sFile, CGameManager::GetGfx());

	m_SpriteMap[sFile] = Spr;

	return Spr;
}

void CSpriteManager::Init()
{
}

void CSpriteManager::Destroy()
{
	std::map<CStringW, CSprite*>::iterator iter = m_SpriteMap.begin();

	while (iter != m_SpriteMap.end())
	{
		delete iter->second;
		m_SpriteMap.erase(iter++);
	}
	if (m_SpriteMap.empty() != false)
	{
		m_SpriteMap.clear();
	}
}
