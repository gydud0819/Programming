#include "Play.h"
#include <stdbool.h>

// 강화 게임에 필요한 전역 변수들
// 게임 목표
int CurrentLevel = 0;	// 현재 레벨
int TargetLevel  = 10;	// 목표 레벨
bool IsClear = false;

// 방해 요인 - 재화
int CurrentMoney = 10000;
int UpgradeCost = 1000;
bool IsFail = false;	// 재화가 일정 이하 일 때

void ShowTitle()
{
	printf("게임이 로딩중입니다.......\n");
	printf("================================\n");
	printf("================================\n");
	printf("================================\n\n");

	printf("무기 강화 게임을 시작합니다! >3<	\n\n");
	printf("--------------------------------\n");
}

void ShowManual()
{
	// 1. 조작 방법
	printf("	<조작 방법>\n\n");
	printf("1. 키보드 입력 및 엔터키를 눌러서 선택합니다!\n");
	printf("2. 입력 조건 이외의 키를 누를시 재선택을 합니다!\n\n");

	printf("--------------------------------\n");

	// 2. 게임 목표
	printf("	<게임 목표>\n\n");
	printf("♥ 무기 10강 만들기 ♥\n\n");

	printf("--------------------------------\n");

	// 3. 방해 요소
	printf("	<게임 플레이 요소>\n\n");
	printf("1. 한정된 재화로 목표를 달성해야 해요!\n");
	printf("2. 특정 레벨에서 강화에 실패해 하강할 수도 있어요!\n");
	printf("3. 특정 레벨에서 무기가 파괴될 수도 있어요!\n\n");

	printf("--------------------------------\n");
}

void GameLogic()	// EnforceWeapon.h
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

	}

	if (IsClear)
	{
		// 게임 클리어
		printf("Game Clear♥\n");
		
	}
	if (IsFail)
	{
		// 게임 오버
		printf("Game Over...??\n");
	}
}

void GameLoop()
{
	ShowTitle();
	ShowManual();
	GameLogic();
}
