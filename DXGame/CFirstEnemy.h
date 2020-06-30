#pragma once
class CFirstEnemy : public CEnemy
{
private:
	CSprite* m_SpriteHP;
	D2D1_RECT_F	m_rTiledHP;

public:
	CFirstEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CFirstEnemy();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
};

