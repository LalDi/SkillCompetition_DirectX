#include "pch.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	RemoveAllObject();
}

void CScene::AddObject(CGameObject* p_pObject)
{
	m_Objects.push_back(p_pObject);
}

void CScene::RemoveObject(CGameObject* p_pObject)
{
	std::list<CGameObject*>::iterator iter;
	for (iter = m_Objects.begin(); iter != m_Objects.end(); iter++) {
		if ((*iter) == p_pObject) 
		{
			m_Objects.erase(iter);
			break;
		}
	}
}

void CScene::UpdateAllObject(DWORD elapsed)
{
	for (auto iter : m_Objects)
		iter->Update(elapsed);

	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->m_isLive == false)
		{
			if (*iter)
			{
				delete* iter;
				*iter = nullptr;
			}
			iter = m_Objects.erase(iter);
		}
		if (iter != m_Objects.end())
			iter++;
	}
}

void CScene::ControlAllObject(CInput* pInput)
{
	std::list<CGameObject*>::iterator iter;
	for (iter = m_Objects.begin(); iter != m_Objects.end(); iter++) {
		(*iter)->Control(pInput);
	}
}

void CScene::RenderAllObject()
{
	for (auto iter : m_Objects)
		iter->Render();
}

void CScene::RemoveAllObject()
{
	for (auto iter : m_Objects) {
		if (iter) {
			delete iter;
			iter = nullptr;
		}
	}
	m_Objects.clear();
}
