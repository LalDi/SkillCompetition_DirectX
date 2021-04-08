#pragma once
class CIngameScene : public CScene
{
private:
	cPlayer* Player;
	time_t m_MobSpawn = timeGetTime();
	time_t m_AsteroidSpawn = timeGetTime();
	float m_MobDelay;
	float m_AsteroidDelay;
	bool b_isGameover = false;

public:
	virtual void Init() override;
	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
	virtual void Release() override;
};

