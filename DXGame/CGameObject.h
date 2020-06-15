#pragma once
class CGameObject : public IGameObject
{
protected:
	D2D1_POINT_2F			m_Pos;
	D2D1_RECT_F				m_Rect;
	CSprite* m_Sprite;

public:
	D2D1_POINT_2F			m_Scale;
	D2D1_RECT_F				m_rTiled;
	INT						m_tag;
	CStringW				m_Name;
	BOOL					m_isLive;

	CGameObject(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int tag = 0);
	virtual ~CGameObject(void);

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

	D2D1_POINT_2F GetPos() { return m_Pos; }
	D2D1_RECT_F GetRect() { return m_Rect; }
};
