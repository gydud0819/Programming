#include "Player.h"
#include "MapBoder.h"

extern int Map1[����][����];		// 1�� ���������� ũ��
extern int Map2[����2][����2];	// 2�� ���������� ũ��

Exit NextStage = { {29, 28 }, true };	// ��������2�� �Ѿ�� ��������1 ��ġ
Exit gameExit = { {29, 2}, true }; // ��������2 �ⱸ ��ǥ

void MovePlayer(Player* playerptr, const Exit* exitptr)
{
	COORD stagePos = { 50,0 };
	// ���� ��ġ �����ϱ�
	playerptr->prevPosX = playerptr->playerPos.posX;
	playerptr->prevPosY = playerptr->playerPos.posY;

	// ���� ���������� ���� ����� �� ����
	int (*currentMap)[����] = (playerptr->CurrentStage == 1) ? Map1 : Map2;	// ���� ������ ���
	
	if (_kbhit())
	{
		SetCurPosition(playerptr->playerPos.posX, playerptr->playerPos.posY);	// �ܻ��� ���� �ʰ� �Ѵ�.
		printf("  ");
		// ȭ��ǥ �Է� �ν� �ֱ�

		// �ڵ尡 ��ġ�ϸ� true (C���� �Է��� ����� �� ����Ѵ�.)
		if (GetAsyncKeyState(VK_UP) & 0x8000) // ��
		{
			playerptr->playerPos.posY--;
			if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)
			{
				playerptr->playerPos.posY++;
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->heartCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 3) // ������ ��ġ
			{
				playerptr->starCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}

		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) // �Ʒ�
		{
			playerptr->playerPos.posY++;
			if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)		// �÷��̾ ���� �մ� ���°� �߻��ϸ� �ȵǱ⿡
				// �÷��̾ ���� ���̸� �ٽ� �ڷ� �з����� ��ó�� ���� ���ϰ� �����Ͽ���.
			{
				playerptr->playerPos.posY--;
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->heartCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 3) // ������ ��ġ
			{
				playerptr->starCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}

		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) // ��
		{
			playerptr->playerPos.posX--;
			if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)	// x�� �� +2 (== 1ĭ�̵�)
			{
				playerptr->playerPos.posX++;
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->heartCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 3) // ������ ��ġ
			{
				playerptr->starCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}

		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // ��
		{
			playerptr->playerPos.posX++;
			if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)
			{
				playerptr->playerPos.posX--;
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->heartCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] == 3) // ������ ��ġ
			{
				playerptr->starCount++;
				currentMap[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}

		}

		// 2. �� ��ġ�� �÷��̾� �׸���
		SetCurPosition(playerptr->playerPos.posX, playerptr->playerPos.posY);
		SetColor(0, 2);
		printf("��");
		SetColor(0, 15);

		// 3. ���� ��ġ ������Ʈ (���� �������� ����)
		playerptr->prevPosX = playerptr->playerPos.posX;
		playerptr->prevPosY = playerptr->playerPos.posY;

		Sleep(100);

	}

	if (playerptr->CurrentStage == 1)
	{
		if (playerptr->heartCount >= 5)
		{
			currentMap[NextStage.exitPos.posY][NextStage.exitPos.posX] = 0; 
			SetCurPosition(30, 28);
			printf("��");
			SetCurPosition(40, 1);
			printf("���� ���������� �̵��մϴ�!\n");
		}
	}

	if (playerptr->playerPos.posX == 29 &&
		playerptr->playerPos.posY == 28)
	{
		// �������� ��ȯ ����
		playerptr->CurrentStage = 2;
		playerptr->playerPos.posX = 1;  // �������� 2 ���� ��ǥ
		playerptr->playerPos.posY = 28;	// �������� 2 ���� ��ǥ
		playerptr->starCount = 0;		 // �� ī��Ʈ ����
		system("cls");
		COORD stagePos = { 50,0 };
		//ShowStage2(Stage2, stagePos);
		ShowClearStage2();				// �� ���ΰ� ������ �ʴ� �Լ�
		return; // �Լ� ��� ����
	}
	else if (playerptr->CurrentStage == 2)
	{
		if (playerptr->starCount >= 5)		// �� 5�� ������ �ⱸ ������
		{
			currentMap[gameExit.exitPos.posY][gameExit.exitPos.posX] = 0;
			SetCurPosition(30, 2);
			printf("��");
			SetCurPosition(40, 2);
			printf("�ⱸ�� Ȱ��ȭ�Ǿ����ϴ�!\n");
		}
		// 2. �ⱸ ���� ����
		if (playerptr->playerPos.posX == gameExit.exitPos.posX &&
			playerptr->playerPos.posY == gameExit.exitPos.posY)
		{
			system("cls");
			SetCurPosition(25, 10);
			//SetColor(0, 2);
			printf("�ڡڡڡڡ� Game Clear �ڡڡڡڡ�");
			exit(0); // ���� ���� ����
		}
	}

}


