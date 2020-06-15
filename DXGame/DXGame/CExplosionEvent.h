#pragma once
class CExplosionEvent : public CGameObject
{
private:
	CSprite* m_Sprites[12];
	time_t m_Timer = timeGetTime();
	int m_ImageCounter = 0;

public:
	CExplosionEvent(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, bool IsEnemy);
	~CExplosionEvent();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
};

