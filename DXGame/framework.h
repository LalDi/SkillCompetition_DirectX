#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일
#include <atlstr.h>
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <Mmsystem.h>
#include <math.h>

#include <map>
#include <list>

// DX 헤더 파일
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>

// 리소스 피일
#include "Resource.h"

// 라이브러리 파일
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "winmm.lib")

// 추가 파일
#include "Utility.h"
#include "CGraphics.h"
#include "Input.h"
#include "CDX2DApp.h"
#include "CSprite.h"

#include "IGameObject.h"
#include "CGameObject.h"
#include "CScene.h"

// 게임 이벤트
#include "CExplosionEvent.h"
#include "CLevelupEvent.h"

// 게임 오브젝트
#include "CBullet.h"
#include "CPlayerBullet.h"
#include "CEnemyBullet.h"
#include "cPlayer.h"
#include "CEnemy.h"
#include "CFirstEnemy.h"
#include "CSecondEnemy.h"
#include "CAsteroidEnemy.h"
#include "CScroolMap.h"

// 게임 UI
#include "CFramemask.h"
#include "CLevelUI.h"
#include "CStatusFrameUI.h"
#include "CHpbarUI.h"
#include "CExpbarUI.h"


// 게임 씬
#include "CIngameScene.h"

// 게임 매니저
#include "CSceneManager.h"
#include "CSpriteManager.h"
#include "CGameManager.h"
#include "CGame.h"

// 매크로 생성
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

#define PI 3.14f
#define ToRadian( degree )  ( (degree) * (PI / 180.0f) )
#define ToDegree( radian )  ( (radian) * (180.0f / PI) )
#define PlayerLevel( Level ) (100 + Level * 200)

enum TAGS {
	TEXTURE,
	PLAYER,
	ENEMY,
	BULLET,
	UI
};

// 변수 생성
const int WinSizeX = 1024;
const int WinSizeY = 1024;