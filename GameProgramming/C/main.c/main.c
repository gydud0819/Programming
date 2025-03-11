/*
* 작성일	: 2025-03-08 ~
* 작성자	: 박효영
* 주제	: 미로 탈출 게임
*/

/*
* 윈도우 콘솔 배경 및 글자 색 변경 방법
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "MapBoder.h"
#include "Console.h"

//커서 이동 함수
void SetCurPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;	// x는 x2를 해야 한칸이 된다.
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

extern int map[20][20];	// 미로의 크기 

int itemCount = 0;	// 아이템 개수

bool Exit = false;	// bool 함수를 사용하여 아이템을 다 먹으면 출구가 활성화 되도록 했다.
int exitX = 19;		// 출구의 X 좌표
int exitY = 18;		// 출구의 Y 좌표

int main()
{
	ShowMap();
	HideCursor();

	int playerX = 10;	// 플레이어의 시작 위치
	int playerY = 1;	// 플레이어의 시작 위치

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
				playerY--;
				if (map[playerY][playerX] == 1)
				{
					playerY++;
				}
				else if (map[playerY][playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerY][playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerX == exitX && playerY == exitY)
				{
					Exit = true; // 출구에 도달하면 게임 종료
				}
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 아래
			{
				playerY++;
				if (map[playerY][playerX] == 1)		// 플레이어가 벽을 뚫는 사태가 발생하면 안되기에 
					// 플레이어가 벽에 닿이면 다시 뒤로 밀려나는 것처럼 뚫지 못하게 설정하였다.
				{
					playerY--;
				}
				else if (map[playerY][playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerY][playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerX == exitX && playerY == exitY)
				{
					Exit = true; // 출구에 도달하면 게임 종료
				}
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 좌
			{
				playerX--;
				if (map[playerY][playerX] == 1)	// x의 값 +2 (== 1칸이동)
				{
					playerX++;
				}
				else if (map[playerY][playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerY][playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerX == exitX && playerY == exitY)
				{
					Exit = true; // 출구에 도달하면 게임 종료
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 우
			{
				playerX++;
				if (map[playerY][playerX] == 1)
				{
					playerX--;
				}
				else if (map[playerY][playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerY][playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerX == exitX && playerY == exitY)
				{
					Exit = true; // 출구에 도달하면 게임 종료
				}

			}
			else
			{
				// x,y 가 움직이지 않을때 그대로 
			}
		}

		if (itemCount == 4)	// 아이템을 다 먹으면 출구가 생성된다.
		{
			
			map[exitY][exitX] = 0;
			SetCurPosition(25, 0);
			printf("출구가 활성화 되었습니다!");
			ShowMap();	// 출구를 생성하기 위해 맵 다시 그리게 맵 함수를 한번 더 사용했다.
			
		}

		SetCurPosition(playerX, playerY);
		SetColor(0, 2);
		printf("옷");
		SetColor(0, 15);


		Sleep(100);

		
		if(Exit)
		{
			system("cls");
			SetCurPosition(25, 10);
			SetColor(0, 4);
			printf("Game Celar!");	// 출구로 나가면 Game Clear가 뜨면서 종료가 된다.

			break;
		}

	}
}




