#include "Intro.h"
#include <stdbool.h>

void IntroMenu()
{
	while (true)
	{
		// UI 텍스트
		printf("1. 게임시작\n");
		printf("2. 게임종료\n");

		// 로직
		// 입력으로 실행하는 방식
		// 변수에 값을 비교해서 실행한다.
		int InputNumber = 1;			// 입력받을 변수 이름
		scanf_s("%d", &InputNumber);	// 입력받는 함수 (stdio.h)
		while (getchar() != '\n');		// 입력 버퍼를 비우기 위한 코드

		// 비교 연산자 '==' -> 조건문을 함께 사용한다.
		if (InputNumber == 1)
		{
			// 게임 시작
			GameLoop();
		}
		else if (InputNumber == 2)
		{
			// 게임 종료
			break;
		}
		else
		{
			// 잘못된 값을 입력했다.
			// printf("잘못된 값을 입력했습니다.\n");
		}
	}
}
