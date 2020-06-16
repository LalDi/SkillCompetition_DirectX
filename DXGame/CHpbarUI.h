#pragma once
class CHpbarUI : public CGameObject
{
private:
	int m_NowHp;
	int m_MaxHp;
	cPlayer* Player;

public:
	CHpbarUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, cPlayer* player);
	~CHpbarUI();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

	void SetHp(int value) { m_NowHp = value; }
};

