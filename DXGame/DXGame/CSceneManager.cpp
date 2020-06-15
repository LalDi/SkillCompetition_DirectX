#include "pch.h"

CSceneManager::CSceneManager()
	:m_NowScene(nullptr), m_NextScene(nullptr)
{
}

CSceneManager::~CSceneManager()
{
	Release();
}

CScene* CSceneManager::AddScene(const CStringW& name, CScene* ScenePtr)
{
	if (!ScenePtr)
		return nullptr;
	if (m_SceneMap.find(name) != m_SceneMap.end())
		return nullptr;

	m_SceneMap.insert(std::make_pair(name, ScenePtr));
	return ScenePtr;
}

CScene* CSceneManager::ChangeScene(const CStringW& name)
{
	auto find = m_SceneMap.find(name);
	if (find == m_SceneMap.end())
		return nullptr;

	m_NextScene = find->second;
	return m_NextScene;
}

void CSceneManager::Update(DWORD elapsed)
{
	if (m_NextScene)//������� ���� �ִ��� Ȯ���غ���
	{
		if (m_NowScene)//���� ���� ������
			m_NowScene->Release();//����ְ�
		m_NextScene->Init();
		m_NowScene = m_NextScene;//���� �ٲ��ش�
		m_NextScene = nullptr;
	}
	if (m_NowScene)
		m_NowScene->Update(elapsed);
}

void CSceneManager::Control(CInput* Input)
{
	if (m_NowScene)
		m_NowScene->Control(Input);
}

void CSceneManager::Render()
{
	if (m_NowScene)
		m_NowScene->Render();
}

void CSceneManager::Release()
{
	if (m_NowScene)
		m_NowScene->Release();

	for (auto iter : m_SceneMap)
		delete(iter.second);

	m_SceneMap.clear();
}
