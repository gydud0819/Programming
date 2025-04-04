#include "Player.h"
#include "MapBoder.h"

extern int map[20][20];	// �̷��� ũ��

//int exitX = 19;		// �ⱸ�� X ��ǥ
//int exitY = 18;		// �ⱸ�� Y ��ǥ

Exit gameExit = { {19, 18 }, true };	// �ⱸ�� ��ġ

void MovePlayer(Player* playerptr, const Exit* exitptr)
{
	if (_kbhit())
	{
		SetCurPosition(playerptr->playerPos.posX, playerptr->playerPos.posY);	// �ܻ��� ���� �ʰ� �Ѵ�.
		printf("  ");
		// ȭ��ǥ �Է� �ν� �ֱ�

		// �ڵ尡 ��ġ�ϸ� true (C���� �Է��� ����� �� ����Ѵ�.)
		if (GetAsyncKeyState(VK_UP) & 0x8000) // ��
		{
			playerptr->playerPos.posY--;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)
			{
				playerptr->playerPos.posY++;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->NextStage = true; // ���� ���������� �̵�
			}
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) // �Ʒ�
		{
			playerptr->playerPos.posY++;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)		// �÷��̾ ���� �մ� ���°� �߻��ϸ� �ȵǱ⿡
				// �÷��̾ ���� ���̸� �ٽ� �ڷ� �з����� ��ó�� ���� ���ϰ� �����Ͽ���.
			{
				playerptr->playerPos.posY--;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->mazeExit = true; // �ⱸ�� �����ϸ� ���� ����
			}
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) // ��
		{
			playerptr->playerPos.posX--;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)	// x�� �� +2 (== 1ĭ�̵�)
			{
				playerptr->playerPos.posX++;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->mazeExit = true; // �ⱸ�� �����ϸ� ���� ����
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // ��
		{
			playerptr->playerPos.posX++;
			if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 1)
			{
				playerptr->playerPos.posX--;
			}
			else if (map[playerptr->playerPos.posY][playerptr->playerPos.posX] == 2) // ������ ��ġ
			{
				playerptr->itemCount++;
				map[playerptr->playerPos.posY][playerptr->playerPos.posX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerptr->playerPos.posX == exitptr->exitPos.posX && playerptr->playerPos.posY == exitptr->exitPos.posY)
			{
				playerptr->mazeExit = true;

			}
			else
			{
				// x,y �� �������� ������ �״��
			}
		}

		if (playerptr->itemCount == 4)	// �������� �� ������ �ⱸ�� �����ȴ�.
		{
			map[exitptr->exitPos.posY][exitptr->exitPos.posX] = 0;
			SetCurPosition(25, 0);
			printf("���� ���������� �Ѿ�ϴ�!");	// ���� ���������� �Ѿ�ϴٷ� ���� ����
			ShowMap2();	// �ⱸ�� �����ϱ� ���� �� �Լ��� �� �� �� ȣ���ߴ�.
		}

		SetCurPosition(playerptr->playerPos.posX, playerptr->playerPos.posY);
		SetColor(0, 2);
		printf("��");
		SetColor(0, 15);


		Sleep(100);
			
	}

}


