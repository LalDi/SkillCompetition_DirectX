#pragma once
class CEnemyBullet : public CBullet
{
private:

public:
	CEnemyBullet(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int Angle, int Damage);
	~CEnemyBullet();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
};

