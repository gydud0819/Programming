#include "MapBoder.h"
#include "Console.h"
#include "Player.h"

extern int Map1[����][����];	// �̷��� ũ��
extern int Map2[����2][����2];	// �̷��� ũ��

int main()
{
	COORD stagePos = { 50,0 };
	//ShowStage1(Stage1, stagePos);			// �̷� ���ΰ� ���̴� �Լ�
	ShowClearStage1(Stage1, stagePos);			// �̷� ���ΰ� ������ �ʴ� �Լ�
	//ShowStage2();			// �ι�° �������� ��
	HideCursor();

	int playerX = 11;	// �÷��̾��� ���� ��ġ
	int playerY = 2;	// �÷��̾��� ���� ��ġ

	SetCurPosition(playerX, playerY);
	printf("��");

	Player player;
	player.playerShape = "��";
	player.playerPos.posX = 11;
	player.playerPos.posY = 2;
	player.mazeExit = false;
	player.heartCount = 0;
	player.starCount = 0;	// 2��° �������� ������ �ʱ�ȭ
	player.CurrentStage = 1;

	Exit exit;
	exit.exitPos.posX = 29;
	exit.exitPos.posY = 2;
	exit.exit = false;

	SetCurPosition(player.playerPos.posX, player.playerPos.posY);
	SetColor(0, 2);
	printf("��");
	SetColor(0, 15);
		
	while (true)
	{
		int prevX = player.playerPos.posX;
		int prevY = player.playerPos.posY;

		// ���� �κ� ȭ�� ���� ����
		if (prevX != player.playerPos.posX || prevY != player.playerPos.posY) 
		{
			SetCurPosition(prevX, prevY);
			printf(" "); // ���� ��ġ �����
			SetCurPosition(player.playerPos.posX, player.playerPos.posY);
			SetColor(0, 2);
			printf("��");
			SetColor(0, 15);
		}
				
		MovePlayer(&player, &exit);

		Sleep(50);
		

	}
}