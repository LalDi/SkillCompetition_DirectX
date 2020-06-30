#pragma once
class CEnemy : public CGameObject
{
protected:
	int m_Hp;
	int m_MaxHp;
	float m_Speed;
	int m_Damage;
	float m_AttackSpeed;
	int m_GiveExp;

	time_t m_bulletTimer = timeGetTime();

public:
	CEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CEnemy();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

	bool OutMap();
	bool IsFire();
	int GetGiveExp() { return m_GiveExp; }
	int GetDamage() { return m_Damage; }
	int GetHp() { return m_Hp; }
	void MinusHp(int value) { m_Hp -= value; }
};

