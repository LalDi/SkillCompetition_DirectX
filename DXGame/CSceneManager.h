#pragma once
class CSceneManager
{
private:
	CScene* m_NowScene;
	CScene* m_NextScene;
	std::map<CStringW, CScene*> m_SceneMap;

public:
	CSceneManager();
	~CSceneManager();

	CScene* AddScene(const CStringW& name, CScene* ScenePtr);
	CScene* ChangeScene(const CStringW& name);

	void Update(DWORD elapsed);
	void Control(CInput* Input);
	void Render();
	void Release();
};

