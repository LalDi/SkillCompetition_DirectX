#pragma once
class CScroolMap : public CGameObject
{
public:
	CScroolMap(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CScroolMap();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
};

