/*
* �ۼ���	: 2025-03-08 ~
* �ۼ���	: ��ȿ��
* ����	: �̷� Ż�� ����
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "MapBoder.h"

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

//void SetCurPosition(int x, int y);

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
				playerY -= 1;
				if (playerY <= 0)
				{
					playerY = 1;
				}
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000) // �Ʒ�
			{
				playerY += 1;
				if (playerY >= 19)		// �� �浹�� �����ϱ� ���� 20 18�� ������ ���� ������� ��� 
					// 20 18�� ��߳��� ���� �� �� �־� 19 17�� �����ߴ�.
				{
					playerY = 17;
				}
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) // ��
			{
				playerX -= 2;
				if (playerX < 2)	// x�� �� +2 (== 1ĭ�̵�)
				{
					playerX = 1;
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // ��
			{
				playerX += 2;
				if (playerX > 19)
				{
					playerX = 18;
				}
			}
			else
			{
				// x,y �� �������� ������ �״�� 
			}

		}
		SetCurPosition(playerX, playerY);
		printf("��");

		Sleep(50);
	}
}




