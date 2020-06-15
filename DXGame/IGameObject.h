#pragma once
class IGameObject					//05
{
public:
	virtual ~IGameObject() {};

	virtual void Update(DWORD elapsed) = 0;
	virtual void Render() = 0;
	virtual void Control(CInput* Input) = 0;	//07
};