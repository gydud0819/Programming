/*
* 작성일	: 2025-03-08 ~
* 작성자	: 박효영
* 주제	: 미로 탈출 게임
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "MapBoder.h"

//커서 이동 함수
void SetCurPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 숨기기 함수
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false; // 안보이게
	info.dwSize = 1; //커서의 크기값

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

//void SetCurPosition(int x, int y);

int main()
{
	ShowMap();
	HideCursor();

	int playerX = 10;
	int playerY = 1;

	SetCurPosition(playerX, playerY);
	printf("옷");

	while (true)
	{
		if (_kbhit())
		{
			SetCurPosition(playerX, playerY);	// 잔상이 남지 않게 한다. 
			printf("  ");
			// 화살표 입력 인식 넣기

			// 코드가 일치하면 true (C언어에서 입력을 사용할 때 사용한다.)
			if (GetAsyncKeyState(VK_UP) & 0x8000) // 위
			{
				playerY -= 1;
				if (playerY <= 0)
				{
					playerY = 1;
				}
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 아래
			{
				playerY += 1;
				if (playerY >= 19)		// 벽 충돌을 방지하기 위해 20 18이 맞지만 직접 디버그한 결과 
					// 20 18은 어긋나는 것을 볼 수 있어 19 17로 설정했다.
				{
					playerY = 17;
				}
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 좌
			{
				playerX -= 2;
				if (playerX < 2)	// x의 값 +2 (== 1칸이동)
				{
					playerX = 1;
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 우
			{
				playerX += 2;
				if (playerX > 19)
				{
					playerX = 18;
				}
			}
			else
			{
				// x,y 가 움직이지 않을때 그대로 
			}

		}
		SetCurPosition(playerX, playerY);
		printf("옷");

		Sleep(50);
	}
}




