#include "WindowAPI.h"
#include "MapBoder.h"

extern int map[20][20];	// �̷��� ũ��

//Ŀ�� �̵� �Լ�
void SetCurPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;	// x�� x2�� �ؾ� ��ĭ�� �ȴ�.
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ŀ�� ����� �Լ�
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false; // �Ⱥ��̰�
	info.dwSize = 1; //Ŀ���� ũ�Ⱚ
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void PlayerInputKey()
{
	if (_kbhit())
	{
		SetCurPosition(playerX, playerY);	// �ܻ��� ���� �ʰ� �Ѵ�.
		printf("  ");
		// ȭ��ǥ �Է� �ν� �ֱ�

		// �ڵ尡 ��ġ�ϸ� true (C���� �Է��� ����� �� ����Ѵ�.)
		if (GetAsyncKeyState(VK_UP) & 0x8000) // ��
		{
			playerY--;
			if (map[playerY][playerX] == 1)
			{
				playerY++;
			}
			else if (map[playerY][playerX] == 2) // ������ ��ġ
			{
				itemCount++;
				map[playerY][playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerX == exitX && playerY == exitY)
			{
				Exit = true; // �ⱸ�� �����ϸ� ���� ����
			}
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) // �Ʒ�
		{
			playerY++;
			if (map[playerY][playerX] == 1)		// �÷��̾ ���� �մ� ���°� �߻��ϸ� �ȵǱ⿡
				// �÷��̾ ���� ���̸� �ٽ� �ڷ� �з����� ��ó�� ���� ���ϰ� �����Ͽ���.
			{
				playerY--;
			}
			else if (map[playerY][playerX] == 2) // ������ ��ġ
			{
				itemCount++;
				map[playerY][playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerX == exitX && playerY == exitY)
			{
				Exit = true; // �ⱸ�� �����ϸ� ���� ����
			}
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) // ��
		{
			playerX--;
			if (map[playerY][playerX] == 1)	// x�� �� +2 (== 1ĭ�̵�)
			{
				playerX++;
			}
			else if (map[playerY][playerX] == 2) // ������ ��ġ
			{
				itemCount++;
				map[playerY][playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerX == exitX && playerY == exitY)
			{
				Exit = true; // �ⱸ�� �����ϸ� ���� ����
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // ��
		{
			playerX++;
			if (map[playerY][playerX] == 1)
			{
				playerX--;
			}
			else if (map[playerY][playerX] == 2) // ������ ��ġ
			{
				itemCount++;
				map[playerY][playerX] = 0; // ������ �԰� ��ġ �ʱ�ȭ
			}
			else if (playerX == exitX && playerY == exitY)
			{
				Exit = true; // �ⱸ�� �����ϸ� ���� ����
			}

		}
		else
		{
			// x,y �� �������� ������ �״��
		}
	}
}
