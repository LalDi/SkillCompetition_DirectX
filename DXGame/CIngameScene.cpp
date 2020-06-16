#include "pch.h"

void CIngameScene::Init()
{
	CGameObject* ScrollTemp1;
	CGameObject* ScrollTemp2;

	CGameObject* UITemp0;
	CGameObject* UITemp1;
	CGameObject* UITemp2;
	CGameObject* UITemp3;

	ScrollTemp1 = new CScroolMap(L"./Images/Background.png", D2D1::Point2F(0, -1024), 1024, 1024);
	AddObject(ScrollTemp1);
	ScrollTemp2 = new CScroolMap(L"./Images/Background.png", D2D1::Point2F(0, 0), 1024, 1024);
	AddObject(ScrollTemp2);

	Player = new cPlayer(L"./Images/Player.png", D2D1::Point2F(WinSizeX / 2, 800), 124, 135);
	AddObject(Player);

	UITemp0 = new CFramemask(L"./Images/UI/UI_FrameMask.png", D2D1::Point2F(20, 20), 814, 253);
	AddObject(UITemp0);
	UITemp1 = new CHpbarUI(L"./Images/UI/UI_Hp.png", D2D1::Point2F(320, 85), 426, 42, Player);
	AddObject(UITemp1);
	UITemp2 = new CExpbarUI(L"./Images/UI/UI_Exp.png", D2D1::Point2F(320, 145), 426, 42, Player);
	AddObject(UITemp2);
	UITemp3 = new CStatusFrameUI(L"./Images/UI/UI_Frame.png", D2D1::Point2F(20, 20), 814, 253);
	AddObject(UITemp3);

	m_MobDelay = 1500;
	m_AsteroidDelay = 10000;
}

void CIngameScene::Update(DWORD elapsed)
{
	if (Player->GetIsFire())
		if (Player->GetShootMode())
			AddObject(Player->Fire(Player->GetAngle()));
		else
			for (int i = -2; i < 3; i++)
				AddObject(Player->Fire(Player->GetAngle() + i * 5));

	if (timeGetTime() - m_MobSpawn > m_MobDelay)
	{
		if (rand() % 2 == 0)
			AddObject(new CFirstEnemy(L"./Images/Enemy1.png", D2D1::Point2F(rand() % (WinSizeX - 40), 70), 40, 55));
		else
			AddObject(new CSecondEnemy(L"./Images/Enemy2.png", D2D1::Point2F(rand() % (WinSizeX - 36), 70), 36, 44));
		m_MobSpawn = timeGetTime();
	}

	if (timeGetTime() - m_AsteroidSpawn > m_AsteroidDelay)
	{
		AddObject(new CAsteroidEnemy(L"./Images/Asteroid.png", D2D1::Point2F(rand() % (WinSizeX - 106), 0), 106, 96));
		m_AsteroidSpawn = timeGetTime();
	}

	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
	{
		if ((*iter)->m_tag == ENEMY)
		{
			if (RectCircleCrashCheck(Player->GetPos(), Player->GetRadius(), (*iter)->GetRect()))
			{
				Player->SetHp(Player->GetHp() - ((CEnemy*)(*iter))->GetDamage());
				AddObject(new CExplosionEvent(L"./Images/Explosion/explosion1.png", (*iter)->GetPos(), 64, 64, true));
				(*iter)->m_isLive = false;
			}

			if (((CEnemy*)(*iter))->IsFire())
				AddObject(new CEnemyBullet(L"./Images/Bullet.png", ((CEnemy*)(*iter))->GetPos(), 8, 25, 180, ((CEnemy*)(*iter))->GetDamage()));
		}
		if ((*iter)->m_tag == BULLET)
		{
			if (((CBullet*)(*iter))->GetBulletState()) // 플레이어 총알
			{
				for (auto iter2 = m_Objects.begin(); iter2 != m_Objects.end(); iter2++)
				{
					if ((*iter2)->m_tag == ENEMY)
					{
						if (RectCrashCheck(((CBullet*)(*iter))->GetRect(), (*iter2)->GetRect()))
						{
							((CEnemy*)(*iter2))->MinusHp(((CBullet*)(*iter))->GetDamage());
							if (((CEnemy*)(*iter2))->GetHp() <= 0)
							{
								Player->PlusExp(((CEnemy*)(*iter2))->GetGiveExp());
								AddObject(new CExplosionEvent(L"./Images/Explosion/explosion1.png", (*iter)->GetPos(), 64, 64, true));
								if (Player->GetExp() >= 100)
									AddObject(new CLevelupEvent(L"./Images/LevelUp.png", D2D1::Point2F(WinSizeX / 2, WinSizeY / 2), 720, 360));
							}
							(*iter)->m_isLive = false;
						}
					}
				}
			}
			else // 에너미 총알
			{
				if (RectCircleCrashCheck(Player->GetPos(), Player->GetRadius(), ((CBullet*)(*iter))->GetRect()))
				{
					Player->SetHp(Player->GetHp() - ((CBullet*)(*iter))->GetDamage());
					if (Player->GetHp() <= 0)
						AddObject(new CExplosionEvent(L"./Images/Explosion/explosion1.png", Player->GetPos(), 64, 64, false));
					(*iter)->m_isLive = false;
				}
			}
		}
	}

	CScene::UpdateAllObject(elapsed);
}

void CIngameScene::Control(CInput* Input)
{
	CScene::ControlAllObject(Input);
}

void CIngameScene::Render()
{
	CScene::RenderAllObject();
}

void CIngameScene::Release()
{
}
