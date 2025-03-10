#pragma once
class cPlayer : public CGameObject
{
private:
	float m_Radius;

	float m_Speed;
	float m_Angle;
	float m_FireStart;

	int m_Level;
	int m_Exp;
	int m_Hp;
	int m_MaxHp;
	float m_AttackSpeed;
	int m_Damage;
	float m_Delay;

	bool b_Fire;
	bool b_ShootMode;

public:
	cPlayer(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~cPlayer();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

	CGameObject* Fire(float Angle);

	int GetLevel() { return m_Level; }
	int GetHp() { return m_Hp; }
	int GetMaxHp() { return m_MaxHp; }
	void SetHp(int value) { m_Hp = value; }
	int GetExp() { return m_Exp; }
	void SetExp(int value) { m_Exp = value; }
	void PlusExp(int value) { if (m_Level < 5) m_Exp += value; }
	float GetRadius() { return m_Radius; }
	float GetAngle() { return m_Angle; }
	bool GetIsFire() { return b_Fire; }
	bool GetShootMode() { return b_ShootMode; }
};