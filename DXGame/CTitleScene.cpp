#include "pch.h"

void CTitleScene::Init()
{
}

void CTitleScene::Update(DWORD elapsed)
{
	CScene::UpdateAllObject(elapsed);
}

void CTitleScene::Control(CInput* Input)
{
	CScene::ControlAllObject(Input);
}

void CTitleScene::Render()
{
	CScene::RenderAllObject();
}

void CTitleScene::Release()
{
	
}
