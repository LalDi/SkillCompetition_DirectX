#pragma once
class CDX2DApp
{
protected:
	LPCWSTR					m_sCls;
	HINSTANCE				m_hInst;
	HWND					m_hWnd;
	DWORD					m_dWinStyle;
	DWORD					m_dScnX;			// Screen Width
	DWORD					m_dScnY;			// Screen Height
	BOOL					m_bShowCusor;			// Show Cusor

	RECT					m_rcWin;			// Saved client area size for mode switches

	DWORD					m_fps;

	CInput *				m_Input;

protected:
	CGraphics* m_Gfx;

public:
	CDX2DApp();
	virtual ~CDX2DApp();

	INT		Create(HINSTANCE hInst);
	INT		Run();
	void	Cleanup();

	INT		RenderLoop();

	virtual INT		Init();
	virtual INT		Render();
	virtual INT		Update(DWORD elpased);
	virtual INT		Control(CInput* Input);

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	static LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
};

