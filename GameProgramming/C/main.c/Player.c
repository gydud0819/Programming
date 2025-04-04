#include "Player.h"
#include "MapBoder.h"

extern int map[20][20];	// 미로의 크기

//int exitX = 19;		// 출구의 X 좌표
//int exitY = 18;		// 출구의 Y 좌표

Exit gameExit = { {19, 18 }, true };	// 출구의 위치

void MovePlayer(Player* playerptr, const Exit* exitptr)
{
	if (_kbhit())
	{
		SetCurPosition(playerptr->playerPos.posX, playerptr->playerPos.posY);	// 잔상이 남지 않게 한다.
		printf("  ");
		// 화살표 입력 인식 넣기

		// 코드가 일치하면 true (C언어에서 입력을 사용할 때 사용한다.)
		if (GetAsyncKeyState(VK_UP) & 0x8000) // 위
		{
			playerptr->playerPos.posY--;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)
			{
				playerptr->playerPos.posY++;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // 아이템 위치
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->NextStage = true; // 다음 스테이지로 이동
			}
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 아래
		{
			playerptr->playerPos.posY++;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)		// 플레이어가 벽을 뚫는 사태가 발생하면 안되기에
				// 플레이어가 벽에 닿이면 다시 뒤로 밀려나는 것처럼 뚫지 못하게 설정하였다.
			{
				playerptr->playerPos.posY--;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // 아이템 위치
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->mazeExit = true; // 출구에 도달하면 게임 종료
			}
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 좌
		{
			playerptr->playerPos.posX--;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)	// x의 값 +2 (== 1칸이동)
			{
				playerptr->playerPos.posX++;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // 아이템 위치
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->mazeExit = true; // 출구에 도달하면 게임 종료
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 우
		{
			playerptr->playerPos.posX++;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)
			{
				playerptr->playerPos.posX--;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // 아이템 위치
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->mazeExit = true;

			}
			else
			{
				// x,y 가 움직이지 않을때 그대로
			}
		}

		if (playerptr->itemCount == 4)	// 아이템을 다 먹으면 출구가 생성된다.
		{
			map[exitptr->exitPos.posY][exitptr->exitPos.posX] = 0;
			SetCurPosition(25, 0);
			printf("다음 스테이지로 넘어갑니다!");	// 다음 스테이지로 넘어갑니다로 수정 예정
			ShowMap2();	// 출구를 생성하기 위해 맵 함수를 한 번 더 호출했다.
		}

		SetCurPosition(playerptr->playerPos.posX, playerptr->playerPos.posY);
		SetColor(0, 2);
		printf("옷");
		SetColor(0, 15);


		Sleep(100);
			
	}

}


