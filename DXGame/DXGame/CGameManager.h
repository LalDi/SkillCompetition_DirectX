#pragma once
class CGameManager
{
private:
	static CGraphics* m_Gfx;
	static CSpriteManager* m_ImageManager;
	static CInput* m_Input;

public:
	CGameManager();
	~CGameManager();

	static void Init(CInput* Input, CGraphics* gfx, CSpriteManager* ImageMgr);

	static CGraphics* GetGfx() { return m_Gfx; }
	static CSpriteManager* GetSpriteManager() { return m_ImageManager; }
};