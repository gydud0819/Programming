/*
* �ۼ���	: 2025-03-08 ~
* �ۼ���	: ��ȿ��
* ����	: �̷� Ż�� ����
*/

/*
* ������ �ܼ� ��� �� ���� �� ���� ���
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "MapBoder.h"
#include "Exit.h"
#include "Console.h"

//Ŀ�� �̵� �Լ�
void SetCurPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
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

extern int map[20][20];

//void SetCurPosition(int x, int y);

int itemCount = 0;
bool Exit = false;	// �ⱸ

int main()
{
	ShowMap();
	HideCursor();

	int playerX = 10;
	int playerY = 1;

	SetCurPosition(playerX, playerY);
	printf("��");

	while (true)
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

			}
			else
			{
				// x,y �� �������� ������ �״�� 
			}
		}

		SetCurPosition(playerX, playerY);
		printf("��");

		Sleep(100);

		if (itemCount == 4)	// �������� �� ������ �ⱸ�� ���ܾ� �ϴµ�
		{
			SetCurPosition(20, 19);
			printf(" ");
			//ShowMap2();
			
		}
		if(Exit)
		{
			SetCurPosition(30, 30);
			printf("Game Over!");	// �ⱸ�� ������ ���� �ڵ�

			break;
		}

	}
}




