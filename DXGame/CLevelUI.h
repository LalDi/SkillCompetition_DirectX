#pragma once
class CLevelUI : public CGameObject
{
private:
	int m_NowLevel;
	CSprite* m_Sprites[5];
	cPlayer* Player;

public:
	CLevelUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, cPlayer* player);
	~CLevelUI();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
};

