#include "WindowAPI.h"
#include "MapBoder.h"

extern int map[20][20];	// 미로의 크기

int* itemCount = 0;
int* itemCountptr = &itemCount;

int* exitX = 19;
int* exitY = 18;

int* exitXptr = &exitX;
int* exitYptr = &exitY;

Player player = { "●", };

////커서 이동 함수
//void SetCurPosition(int x, int y)
//{
//	COORD pos;
//	pos.X = x * 2;	// x는 x2를 해야 한칸이 된다.
//	pos.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
////커서 숨기기 함수
//void HideCursor()
//{
//	CONSOLE_CURSOR_INFO info;
//	info.bVisible = false; // 안보이게
//	info.dwSize = 1; //커서의 크기값
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
//}

void PlayerInputKey(Player* playerptr, Item* itemptr)
{
	printf("옷");

	while (true)
	{
		if (_kbhit())
		{
			SetCurPosition(playerptr->playerX, playerptr->playerY);	// 잔상이 남지 않게 한다.
			printf("  ");
			// 화살표 입력 인식 넣기

			// 코드가 일치하면 true (C언어에서 입력을 사용할 때 사용한다.)
			if (GetAsyncKeyState(VK_UP) & 0x8000) // 위
			{
				playerptr->playerY--;
				if (map[playerptr->playerY][playerptr->playerX] == 1)
				{
					playerptr->playerY++;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // 출구에 도달하면 게임 종료
				}
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 아래
			{
				playerptr->playerY++;
				if (map[playerptr->playerY][playerptr->playerX] == 1)		// 플레이어가 벽을 뚫는 사태가 발생하면 안되기에
					// 플레이어가 벽에 닿이면 다시 뒤로 밀려나는 것처럼 뚫지 못하게 설정하였다.
				{
					playerptr->playerY--;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // 출구에 도달하면 게임 종료
				}
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 좌
			{
				playerptr->playerX--;
				if (map[playerptr->playerY][playerptr->playerX] == 1)	// x의 값 +2 (== 1칸이동)
				{
					playerptr->playerX++;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // 출구에 도달하면 게임 종료
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 우
			{
				playerptr->playerX++;
				if (map[playerptr->playerY][playerptr->playerX] == 1)
				{
					playerptr->playerX--;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // 아이템 위치
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // 아이템 먹고 위치 초기화
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // 출구에 도달하면 게임 종료
				}

			}
			else
			{
				// x,y 가 움직이지 않을때 그대로
			}
			if (itemptr->itemCount == 4)	// 아이템을 다 먹으면 출구가 생성된다.
			{
				map[playerptr->exitY][playerptr->exitX] = 0;
				SetCurPosition(25, 0);
				printf("출구가 활성화 되었습니다!");
				ShowMap();	// 출구를 생성하기 위해 맵 함수를 한 번 더 호출했다.
			}

			SetCurPosition(playerptr->playerX, playerptr->playerY);
			SetColor(0, 2);
			printf("옷");
			SetColor(0, 15);


			Sleep(100);

			if (exit)
			{
				system("cls");
				SetCurPosition(25, 10);
				SetColor(0, 4);
				printf("Game Celar!");	// 출구로 나가면 Game Clear가 뜨면서 종료가 된다.

				break;
			}
		}
	}
}


void SetCurPosition(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서를 숨기고 싶을 때 (bool true일때 커서가 보이고 false일때 보이지 않는다.)
void SetCursorVisble(bool enable)
{
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.bVisible = enable;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}
