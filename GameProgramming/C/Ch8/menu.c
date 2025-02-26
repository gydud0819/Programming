/*
* menu.h 코드를 ctrl +c , v
*/
#include "menu.h"

int WeaponLv = 1;
int BasicAttack = 10;
int Weight = 5;
int CurrentAttackPower = 0;

void SelectMenu()
{
	while (true)
	{
		system("cls");
		printf("1. 강화한다.\n");
		printf("2. 그만둔다.\n");
		printf("3. 프로그램 종료.\n");

		int inputNumber = 1;
		scanf_s("%d", &inputNumber); //띄어쓰기는 버퍼가 인식하지 않는다 '\n' <- 사용한다.
		while (getchar() != '\n');	// character 입력 버퍼 

		if (inputNumber == 1)
		{
			// 무기의 레벨
			// 무기의 기본 공격력
			// 무기의 가중치
			// 현재 공격력

			// 강화를 무조건 성공하는 case
			// 무기의 레벨을 1상승 시킵니다.
			WeaponLv = WeaponLv + 1;
			// 현재 공격력 = 기본 공격력 + 레벨 * 가중치
			CurrentAttackPower = BasicAttack + WeaponLv * Weight;
			// printf("현재 공격력, 레벨");
			printf("현재 공격력은 %d, 무기의 레벨은 %d입니다.\n", CurrentAttackPower, WeaponLv);
		}
		else if (inputNumber == 2)
		{
			printf("강화를 그만둡니다.\n");
		}
		else if (inputNumber == 3)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else
		{
			printf("잘못된 값을 입력했습니다.\n");
		}

		// 플레이어가 특정키를 입력했을 때 넘어가도록 설정하기

		printf("계속 진행을 하려면 아무 키나 입력하세요.\n");
		_getch();	// 입력 값을 받아오는 명령어
	}
}
