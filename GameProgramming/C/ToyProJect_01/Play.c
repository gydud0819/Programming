#include "Play.h"
#include <stdbool.h>

// 강화 게임에 필요한 전역 변수들
// 게임 목표
int CurrentLevel = 8;
int TargetLevel = 10;
bool IsClear = true;

bool IsFail = false;

void ShowTitle()
{
	printf("게임이 로딩중입니다.......\n");
	printf("================================\n");
	printf("================================\n");
	printf("================================\n\n");

	printf("	무기 강화하기		\n\n");
}

void ShowManual()
{
	// 1. 조작 방법
	printf("조작 방법\n\n");
	printf("키보드 입력 및 엔터키를 눌러서 선택한다.\n");
	printf("입력 조건 이외의 키를 누를시 재선택을 한다.\n\n");

	// 2. 게임 목표
	printf("게임 목표\n\n");
	printf("무기 10강 만들기\n\n");

	// 3. 방해 요소
	printf("게임 플레이 요소\n\n");
	printf("1. 제한된 소지금으로 목표를 달성해야 한다.\n");
	printf("2. 특정 무기레벨에서 강화 하강이 존재한다.\n");
	printf("3. 특정 레벨에서 무기가 파괴된다.\n\n");
}

void GameLogic()
{
	while (true)
	{
		// 메뉴 선택 반환
		ShowMenu();		// EnforceWeapon.h 에 포함되어 있다.

		// 게임을 클리어 했거나 게임오버가 됐을 때
		if (IsClear || IsFail)
		{
			break;
		}

		if (IsClear)
		{
			// 게임 클리어
			//printf("Game Clear\n");
			IsClear = true;
		}
		if (IsFail)
		{
			// 게임 오버
			printf("Game Over\n");
		}

	}
}

void GameLoop()
{
	ShowTitle();
	ShowManual();
	GameLogic();
}
