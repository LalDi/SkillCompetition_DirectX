#pragma once
class CSecondEnemy : public CEnemy
{
private:

public:
	CSecondEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight);
	~CSecondEnemy();

	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;

};

