/*
* menu.h 코드를 ctrl +c , v
*/
#include "menu.h"

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
			Upgrade();
		}
		else if (inputNumber == 2)
		{
			printf("강화를 그만둡니다.\n");
		}
		else if (inputNumber == 3)
		{
			printf("강화를 종료합니다.\n");
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
