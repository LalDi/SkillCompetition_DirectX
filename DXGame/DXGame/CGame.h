#pragma once
//#include "D3DApp.h"

class CGame : public CDX2DApp
{
	//CGameObjectManager*			m_GameObjectManager;
	CSpriteManager*				m_SpriteManager;
	CSceneManager*				m_SceneManager;
	//std::list<CScene*>	m_Scene;

public:

	CGame();
	~CGame();

	virtual INT		Init();
	virtual void	Destroy();

	virtual INT		Update(DWORD elpased);
	virtual INT		Render();
	virtual INT		Control(CInput* Input);

	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);


};

//0322