#include "EnforceWeapon.h"

void ShowMenu()
{
	printf("1. 강화를 합니다!\n");
	printf("2. 현재 상태를 확인합니다!\n");

	int InPutNumber = -1;
	scanf_s("%d", &InPutNumber);
	while (getchar() != '\n');

	if (InPutNumber == 1)
	{
		// 업그레이드 비용을 지불한다.
		if (CanUpgrade(UpgradeCost))
		{
			if (CheckRandomFunc((50)))	// 90% 성공
			{
				Upgrade();
			}
			else						// 실패
			
			{
				printf("강화에 실패했습니다ㅠㅠ\n");
			}

		}

		ShowStatus();



		// 강화한다.
		//printf("강화한다.\n");	//Upgrade 함수로 대체


	}
	else if (InPutNumber == 2)
	{
		// 상태를 확인한다.
		//printf("상태를 확인합니다!\n");		// ShowStatus 함수로 대체
		ShowStatus();
	}
	else
	{
		// 잘못된 값 입력
		printf("해당하는 입력값이 존재하지 않아요ㅠㅠ\n");
		printf("올바른 값을 입력해주세요!\n");
	}

	// 게임 클리어 여부 확인
	if (IsGameClear())
	{
		//printf("게임을 클리어했습니다.\n");
		IsClear = true;
	}
	else
	{
		printf("목표 레벨을 달성하지 못했습니다ㅠㅠ\n");
	}

	printf("계속 진행하려면 아무 버튼을 눌러주세요!\n");
	_getch();
	system("cls");
}

void Upgrade()
{
	// CurrentLevel = CurrentLevel + 1;
	CurrentLevel++;

	printf("강화에 성공했습니다!\n");
}

void ShowStatus()
{
	printf("현재 무기 레벨 : %dLv\n", CurrentLevel);
	// 현재 보유한 금액
	printf("현재 보유 금액 : %d원\n", CurrentMoney);
}

// 현재 무기 레벨 == 최대 레벨
bool IsGameClear()
{
	// 삼항 연산자
	// A ? B : C;
	// A 조건식이 True이면 B를 반환 False이면 C를 반환
	return CurrentLevel == TargetLevel ? true : false;
}
