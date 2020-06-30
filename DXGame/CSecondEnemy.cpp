#include "pch.h"

CSecondEnemy::CSecondEnemy(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight)
	:CEnemy(sFileName, Pos, sprWidth, sprHeight)
{
	m_MaxHp = 50;
	m_Hp = m_MaxHp;
	m_AttackSpeed = 4;
	m_Damage = 2;
	m_GiveExp = 10;

	m_SpriteHP = CGameManager::GetSpriteManager()->LoadData(L"./Images/UI/UI_EnemyHP.png");
	m_rTiledHP = D2D1::RectF(0, 0, 71.f, 7.f);
}

CSecondEnemy::~CSecondEnemy()
{
}

void CSecondEnemy::Update(DWORD elapsed)
{
	CEnemy::Update(elapsed);

	m_SpriteHP->m_sprWidth = ((float)m_Hp / (float)m_MaxHp) * m_SpriteHP->m_imageWidth;
}

void CSecondEnemy::Control(CInput* Input)
{
}

void CSecondEnemy::Render()
{
	CEnemy::Render();
	D2D1_POINT_2F Temp = { m_Pos.x - 35, m_Pos.y - 30 };

	m_SpriteHP->Draw(&m_rTiledHP, Temp, m_Scale, &Temp);
}
