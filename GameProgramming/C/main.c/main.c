#include "MapBoder.h"
#include "Console.h"
#include "Player.h"

extern int map[20][20];	// �̷��� ũ��

//int itemCount = 0;	// ������ ����

//bool Exit = false;	// bool �Լ��� ����Ͽ� �������� �� ������ �ⱸ�� Ȱ��ȭ �ǵ��� �ߴ�.
//int exitX = 19;		// �ⱸ�� X ��ǥ
//int exitY = 18;		// �ⱸ�� Y ��ǥ

int main()
{
	//ShowStage1();			// �̷� ���ΰ� ���̴� ��
	//ClearStage1();			// �̷� ���ΰ� ������ �ʴ� ��
	ShowStage2();			// �ι�° �������� ��
	HideCursor();

	int playerX = 10;	// �÷��̾��� ���� ��ġ
	int playerY = 1;	// �÷��̾��� ���� ��ġ

	SetCurPosition(playerX, playerY);
	printf("��");

	Player player;
	player.playerShape = "��";
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
		//	printf("Game Celar!");	// �ⱸ�� ������ Game Clear�� �߸鼭 ���ᰡ �ȴ�.

		//	break;
		//}

	}
}