#include "pch.h"

CGame::CGame()
{
	srand(time(NULL));

	m_SpriteManager = nullptr;
	m_SceneManager = nullptr;
}


CGame::~CGame()
{
	Destroy();
}

INT CGame::Init()
{
	CDX2DApp::Init();

	srand(time(NULL));

	m_SpriteManager = new CSpriteManager();
	m_SceneManager = new CSceneManager();
	
	CGameManager::Init(m_Input, m_Gfx, m_SpriteManager);

	m_SceneManager->AddScene("Ingame", new CIngameScene);
	m_SceneManager->ChangeScene("Ingame");
		
	return 0;
}
void CGame::Destroy()
{
	if (m_SpriteManager) {
		delete m_SpriteManager;
		m_SpriteManager = nullptr;
	}

	if (m_SceneManager)
	{
		delete m_SceneManager;
		m_SceneManager = nullptr;
	}
}
INT		CGame::Update(DWORD elapsed)
{
	CDX2DApp::Update(elapsed);
	m_SceneManager->Update(elapsed);

	return 0;
}

INT		CGame::Control(CInput* Input) 
{
	m_SceneManager->Control(Input);
	return 0;
}


INT		CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(0.0f, 0.0f, 0.5f);

	m_SceneManager->Render();

	//wchar_t Wstring[100];
	//swprintf(Wstring, 100, L"현재 프레임 : %d\n조작 : WASD, 마우스\n발사 : 좌클릭\n모드 변경 : 우클릭", m_fps);
	m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	//m_Gfx->DrawTextOut(Wstring, D2D1::Point2F(0, 0));

	m_Gfx->EndDraw();

	return 0;
}



LRESULT CGame::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
	case WM_PAINT:
	{
		break;
	}
	}

	return CDX2DApp::MsgProc(hWnd, msg, wParam, lParam);
}