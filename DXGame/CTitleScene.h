#pragma once
class CTitleScene : public CScene
{
public:
	virtual void Init() override;
	virtual void Update(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Render() override;
	virtual void Release() override;
};

