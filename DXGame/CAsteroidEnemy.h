#pragma once
class CAsteroidEnemy : public CEnemy
{
private:
	int m_Angle;
public:
	CAsteroidEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CAsteroidEnemy();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

};

