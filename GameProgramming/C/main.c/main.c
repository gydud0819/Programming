#include "MapBoder.h"
#include "Console.h"
#include "Player.h"

extern int map[20][20];	// 미로의 크기

//int itemCount = 0;	// 아이템 개수

//bool Exit = false;	// bool 함수를 사용하여 아이템을 다 먹으면 출구가 활성화 되도록 했다.
//int exitX = 19;		// 출구의 X 좌표
//int exitY = 18;		// 출구의 Y 좌표

int main()
{
	//ShowStage1();			// 미로 내부가 보이는 맵
	//ClearStage1();			// 미로 내부가 보이지 않는 맵
	ShowStage2();			// 두번째 스테이지 맵
	HideCursor();

	int playerX = 10;	// 플레이어의 시작 위치
	int playerY = 1;	// 플레이어의 시작 위치

	SetCurPosition(playerX, playerY);
	printf("옷");

	Player player;
	player.playerShape = "옷";
	player.playerPos.posX = 10;
	player.playerPos.posY = 1;
	player.mazeExit = false;
	player.itemCount = 0;

	Exit exit;
	exit.exitPos.posX = 19;
	exit.exitPos.posY = 18;
	exit.exit = false;

	while (true)
	{

		//MovePlayer(&player, &exit);
		//
		//if (player.mazeExit)
		//{
		//	system("cls");
		//	SetCurPosition(25, 10);
		//	SetColor(0, 4);
		//	printf("Game Celar!");	// 출구로 나가면 Game Clear가 뜨면서 종료가 된다.

		//	break;
		//}

	}
}