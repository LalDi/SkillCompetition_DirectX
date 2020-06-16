#pragma once
class CStatusFrameUI : public CGameObject
{
public:
	CStatusFrameUI(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CStatusFrameUI();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

};

