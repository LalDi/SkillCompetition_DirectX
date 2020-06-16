#pragma once
class CLevelupEvent : public CGameObject
{
private:
	time_t m_Timer = timeGetTime();
	int m_ViewTime = 500;

public:
	CLevelupEvent(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CLevelupEvent();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
};

