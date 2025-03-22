#include "WindowAPI.h"
#include "MapBoder.h"

extern int map[20][20];	// �̷��� ũ��

int* itemCount = 0;
int* itemCountptr = &itemCount;

int* exitX = 19;
int* exitY = 18;

int* exitXptr = &exitX;
int* exitYptr = &exitY;

Player player = { "��", };

////Ŀ�� �̵� �Լ�
//void SetCurPosition(int x, int y)
//{
//	COORD pos;
//	pos.X = x * 2;	// x�� x2�� �ؾ� ��ĭ�� �ȴ�.
//	pos.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
////Ŀ�� ����� �Լ�
//void HideCursor()
//{
//	CONSOLE_CURSOR_INFO info;
//	info.bVisible = false; // �Ⱥ��̰�
//	info.dwSize = 1; //Ŀ���� ũ�Ⱚ
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
//}

void PlayerInputKey(Player* playerptr, Item* itemptr)
{
	printf("��");

	while (true)
	{
		if (_kbhit())
		{
			SetCurPosition(playerptr->playerX, playerptr->playerY);	// �ܻ��� ���� �ʰ� �Ѵ�.
			printf("  ");
			// ȭ��ǥ �Է� �ν� �ֱ�

			// �ڵ尡 ��ġ�ϸ� true (C���� �Է��� ����� �� ����Ѵ�.)
			if (GetAsyncKeyState(VK_UP) & 0x8000) // ��
			{
				playerptr->playerY--;
				if (map[playerptr->playerY][playerptr->playerX] == 1)
				{
					playerptr->playerY++;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // ������ ��ġ
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // �ⱸ�� �����ϸ� ���� ����
				}
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000) // �Ʒ�
			{
				playerptr->playerY++;
				if (map[playerptr->playerY][playerptr->playerX] == 1)		// �÷��̾ ���� �մ� ���°� �߻��ϸ� �ȵǱ⿡
					// �÷��̾ ���� ���̸� �ٽ� �ڷ� �з����� ��ó�� ���� ���ϰ� �����Ͽ���.
				{
					playerptr->playerY--;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // ������ ��ġ
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // �ⱸ�� �����ϸ� ���� ����
				}
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) // ��
			{
				playerptr->playerX--;
				if (map[playerptr->playerY][playerptr->playerX] == 1)	// x�� �� +2 (== 1ĭ�̵�)
				{
					playerptr->playerX++;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // ������ ��ġ
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // �ⱸ�� �����ϸ� ���� ����
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // ��
			{
				playerptr->playerX++;
				if (map[playerptr->playerY][playerptr->playerX] == 1)
				{
					playerptr->playerX--;
				}
				else if (map[playerptr->playerY][playerptr->playerX] == 2) // ������ ��ġ
				{
					itemCount++;
					map[playerptr->playerY][playerptr->playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
				}
				else if (playerptr->playerX == playerptr->exitX && playerptr->playerY == playerptr->exitY)
				{
					playerptr->exit = true; // �ⱸ�� �����ϸ� ���� ����
				}

			}
			else
			{
				// x,y �� �������� ������ �״��
			}
			if (itemptr->itemCount == 4)	// �������� �� ������ �ⱸ�� �����ȴ�.
			{
				map[playerptr->exitY][playerptr->exitX] = 0;
				SetCurPosition(25, 0);
				printf("�ⱸ�� Ȱ��ȭ �Ǿ����ϴ�!");
				ShowMap();	// �ⱸ�� �����ϱ� ���� �� �Լ��� �� �� �� ȣ���ߴ�.
			}

			SetCurPosition(playerptr->playerX, playerptr->playerY);
			SetColor(0, 2);
			printf("��");
			SetColor(0, 15);


			Sleep(100);

			if (exit)
			{
				system("cls");
				SetCurPosition(25, 10);
				SetColor(0, 4);
				printf("Game Celar!");	// �ⱸ�� ������ Game Clear�� �߸鼭 ���ᰡ �ȴ�.

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

// Ŀ���� ����� ���� �� (bool true�϶� Ŀ���� ���̰� false�϶� ������ �ʴ´�.)
void SetCursorVisble(bool enable)
{
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.bVisible = enable;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}
