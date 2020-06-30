#include "pch.h"

CFirstEnemy::CFirstEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CEnemy(sFileName, Pos, sprWidth, sprHeight)
{
	m_MaxHp = 70;
	m_Hp = m_MaxHp;
	m_AttackSpeed = 2;
	m_Damage = 4;
	m_GiveExp = 15;

	m_SpriteHP = CGameManager::GetSpriteManager()->LoadData(L"./Images/UI/UI_EnemyHP.png");
	m_rTiledHP = D2D1::RectF(0, 0, 71.f, 7.f);
}

CFirstEnemy::~CFirstEnemy()
{
}

void CFirstEnemy::Update(DWORD elapsed)
{
	CEnemy::Update(elapsed);

	m_SpriteHP->m_sprWidth = ((float)m_Hp / (float)m_MaxHp) * m_SpriteHP->m_imageWidth;
}

void CFirstEnemy::Control(CInput* Input)
{
}

void CFirstEnemy::Render()
{
	CEnemy::Render();
	D2D1_POINT_2F Temp = { m_Pos.x - 35, m_Pos.y - 30 };

	m_SpriteHP->Draw(&m_rTiledHP, Temp, m_Scale, &Temp);
}
