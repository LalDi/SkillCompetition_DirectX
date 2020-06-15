#pragma once
class CBullet : public CGameObject
{
protected:
	int m_Damage;

	float m_Speed;
	float m_Angle;

	bool b_PlayerBullet;

public:
	CBullet(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int Angle, int Damage);
	~CBullet();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
	bool OutMap();
	bool GetBulletState() { return b_PlayerBullet; }
	int GetDamage() { return m_Damage; }
};