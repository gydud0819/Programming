/*
* 작성일	: 2025-03-06 / 03-07
* 작성자	: 박효영
* 주제	: 콘솔창에 플레이어가 움직이도록 만들기
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "MapBoder.h"
#include <conio.h>	// _kbhit() 함수를 쓸 수 있는 헤더파일
#include <stdlib.h>
#include "Random.h"

// 커서 : OutPut 결과를 출력하는 위치를 안내해주는 안내 기호.

// 2번째 목표 : 커서 옮기기

// 커서 위치 옮기는 함수
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

// 커서 보이는거 방지하는 함수
//void HideCursor()
//{
//	CONSOLE_CURSOR_INFO info;
//	info.bVisible = false;
//	info.dwSize = 1;
//
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
//}

/*
* 도전 과제
* 플레이어의 시작 위치를 설정하기
* 좌표에 대한 감각을 익히기
* SetCurPos 함수를 이용하여 내가 원하는 위치에 플레이어 배치하기
*/

// 전역변수
bool GameOver = false;	// bool 함수를 사용하여 플레이어가 물체를 만나면 종료되게 하기
int Currentscore = 0;
int randomX = 18;
int randomY = 1;
int playTime = 0;

int questItemPosX = 34;
int questItemPosY = 5;
bool isQuest = false;

int main()
{
	// 1번째 이슈 : " "(공백문자)와 ■의 간격 크기가 다르다. ■ = " " x2
	// 2번째 이슈 : 플레이어가 맵 안에 있도록 하고싶은데 맵 바깥에 있다.

	
	ShowBoder();
	CreateRandomSeed();

	SetCurPosition(randomX, randomY);
	printf("★");

	SetCurPosition(questItemPosX, questItemPosY);
	printf("♣");

	SetCursorVisble(false);

	// 플레이어의 현재 좌표를 설명해주는 변수 선언하기

	int playerX = 10;	// x의 값 +2 (== 1칸이동)
	int playerY = 1;	// y의 값 +1 하면 한칸씩 밑으로 내려간다. 위로는 -1


	// 플레이어가 처음 시작할 때 등장하는 것 만들기

	//HideCursor();
	SetCurPosition(playerX, playerY);
	printf("□");	// 현재 커서 위치에 "" 문자를 출력한다.

	
	
	// 게임이 바로 종료되지 않도록 loop 만들기
	// 반복적으로 실행되는 부분
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
					playerX = 2;	
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 우
			{
				playerX += 2;
				if (playerX > 36)
				{
					playerX = 36;
				}
			}
			else
			{
				// x,y 가 움직이지 않을때 그대로 
			}

		}

		//printf("현재 좌표 : (%d, %d)", playerX, playerY); // 테스트 코드 :

		//system("cls");	// 잔상이 남지 않게 쓰기. (불안정한 코드) -> 이걸 쓰면 전체가 지워진다.
		//ShowBoder();
		SetCurPosition(playerX, playerY);
		printf("옷");

		// UI 코드
		SetCurPosition(65, 0);
		printf("Score");

		SetCurPosition(65, 1);
		printf("현재 점수 : %d", Currentscore);

		while (true)
		{
			// 시간 제어 코드
			playTime++;
			//int hour = playTime / 360;
			int minute = playTime / 60;
			int second = playTime % 60;

			SetCurPosition(65, 2);
			printf("플레이 시간 : %02d : %02d", minute, second);

			Sleep(1000);
		}

		if (isQuest)
		{
			SetCurPosition(65, 3);
			printf("퀘스트가 활성화 되었습니다!");
		}

		Sleep(50); 


		// 1. Wait InputKey (특정 키를 눌렀을 때)
		// 2. playerX, playerY 값을 변화시킨다.
		// 3. 해당 좌표로 커서를 위치를 바꾸고 출력한다.

		// 벽통과 안하게 하는방법
		// 플레이어랑 벽이랑 위치가 같아지면 통과하지 못한다. 
		// 조건 if문 쓰기, 위치가 같아질 때

		//break;

		// 캐릭터가 특정 위치에 도달하면 GameOver가 true 바뀌면서 종료되게 하기
		if (playerX == randomX && playerY == randomY)	// 아이템과 플레이어의 위치가 같은 상황
		{
			Currentscore++; // 1. 특정 좌표에 가면 점수가 무한정 오른다.
			// 2. 아이템의 위치가 변경되어야 한다. (좌표를 바꾼다.)
			randomX = ReturnPosX();
			randomY = ReturnPosY();
			SetCurPosition(randomX, randomY);
			printf("★");
		}

		if (playerX == questItemPosX && playerY == questItemPosY)
		{
			isQuest = true;
		}

		if (Currentscore == 10)
		{
			break;
		}
	}
}