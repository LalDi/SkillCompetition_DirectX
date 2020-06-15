#pragma once
class CScene abstract
{
protected:
	std::list<CGameObject*> m_Objects;
public:
	virtual void Init() PURE;
	virtual void Update(DWORD elapsed) PURE;
	virtual void Control(CInput* Input) PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	CScene();
	virtual ~CScene();

	void AddObject(CGameObject* p_pObject);
	void RemoveObject(CGameObject* p_pOjbect);

	void UpdateAllObject(DWORD elapsed);
	void ControlAllObject(CInput* pInput);
	void RenderAllObject();
	void RemoveAllObject();
};

