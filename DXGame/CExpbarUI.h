#pragma once
class CExpbarUI : public CGameObject
{
private:
	int m_NowExp;
	cPlayer* Player;

public:
	CExpbarUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, cPlayer* player);
	~CExpbarUI();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

};

