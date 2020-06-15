#pragma once
class CPlayerBullet : public CBullet
{
protected:

public:
	CPlayerBullet(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int Angle, int Damage);
	~CPlayerBullet();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
};

