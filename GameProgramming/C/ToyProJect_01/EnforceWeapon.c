#include "EnforceWeapon.h"

void ShowMenu()
{
	printf("1. 강화한다.\n");
	printf("2. 현재 상태를 확인한다.\n");

	int InPutNumber = 1;
	scanf_s("%d", &InPutNumber);
	while (getchar() != '\n');

	if (InPutNumber == 1)
	{
		// 강화한다.
		printf("강화한다.\n");	//Upgrade 함수로 대체
	}
	else if (InPutNumber == 2)
	{
		// 상태를 확인한다.
		printf("상태를 확인한다.\n");		// ShowStatus 함수로 대체
	}
	else
	{
		printf("해당하는 입력값이 존재하지 않습니다.\n");
		printf("올바른 값을 입력해주세요.\n");
	}
	if (IsGameClear())
	{
		printf("게임을 클리어했습니다.\n");
	}
	else
	{
		printf("목표 레벨을 달성하지 못했습니다.\n");
	}

	printf("계속 진행하려면 아무 버튼을 눌러주세요.\n");
	_getch();
	system("cls");
}

void Upgrade()
{

}

void ShowStatus()
{
	CurrentLevel++;
}

bool IsGameClear()
{
	// 삼항 연산자
	// A ? B : C;
	// A 조건식이 True이면 B를 반환 False이면 C를 반환
	return true;
}
