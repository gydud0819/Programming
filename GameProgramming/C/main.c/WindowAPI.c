#include "WindowAPI.h"
#include "MapBoder.h"

extern int map[20][20];	// 미로의 크기

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

void PlayerInputKey()
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
}
