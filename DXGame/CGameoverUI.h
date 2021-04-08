#pragma once
class CGameoverUI : public CGameObject
{
public:
	CGameoverUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CGameoverUI();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

};

