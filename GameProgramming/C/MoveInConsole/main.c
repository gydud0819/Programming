/*
* �ۼ���	: 2025-03-06
* �ۼ���	: ��ȿ��
* ����	: �ܼ�â�� �÷��̾ �����̵��� �����
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "MapBoder.h"
#include <conio.h>	// _kbhit() �Լ��� �� �� �ִ� �������
#include <stdlib.h>

// Ŀ�� : OutPut ����� ����ϴ� ��ġ�� �ȳ����ִ� �ȳ� ��ȣ.

// 2��° ��ǥ : Ŀ�� �ű��

// Ŀ�� ��ġ �ű�� �Լ�
void SetCurPosition(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Ŀ�� ���̴°� ���� �Լ�
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

/*
* ���� ����
* �÷��̾��� ���� ��ġ�� �����ϱ�
* ��ǥ�� ���� ������ ������
* SetCurPos �Լ��� �̿��Ͽ� ���� ���ϴ� ��ġ�� �÷��̾� ��ġ�ϱ�
*/

bool GameOver = false;	// bool �Լ��� ����Ͽ� �÷��̾ ��ü�� ������ ����ǰ� �ϱ�

int main()
{
	// 1��° �̽� : " "(���鹮��)�� ���� ���� ũ�Ⱑ �ٸ���. �� = " " x2
	// 2��° �̽� : �÷��̾ �� �ȿ� �ֵ��� �ϰ������ �� �ٱ��� �ִ�.

	
	ShowBoder();

	// �÷��̾��� ���� ��ǥ�� �������ִ� ���� �����ϱ�

	int playerX = 10;	// x�� �� +2 (== 1ĭ�̵�)
	int playerY = 1;	// y�� �� +1 �ϸ� ��ĭ�� ������ ��������. ���δ� -1


	// �÷��̾ ó�� ������ �� �����ϴ� �� �����

	HideCursor();
	SetCurPosition(playerX, playerY);
	printf("��");	// ���� Ŀ�� ��ġ�� "" ���ڸ� ����Ѵ�.

	
	
	// ������ �ٷ� ������� �ʵ��� loop �����
	// �ݺ������� ����Ǵ� �κ�
	while (true)
	{
		if (_kbhit())
		{
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
					playerX = 2;	
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // ��
			{
				playerX += 2;
				if (playerX > 36)
				{
					playerX = 36;
				}
			}
			else
			{
				// x,y �� �������� ������ �״�� 
			}

		}

		//printf("���� ��ǥ : (%d, %d)", playerX, playerY); // �׽�Ʈ �ڵ� :

		system("cls");	// �ܻ��� ���� �ʰ� ����. (�Ҿ����� �ڵ�)
		ShowBoder();
		SetCurPosition(playerX, playerY);
		printf("��");

		Sleep(50); 

		// 1. Wait InputKey (Ư�� Ű�� ������ ��)
		// 2. playerX, playerY ���� ��ȭ��Ų��.
		// 3. �ش� ��ǥ�� Ŀ���� ��ġ�� �ٲٰ� ����Ѵ�.

		// ����� ���ϰ� �ϴ¹��
		// �÷��̾�� ���̶� ��ġ�� �������� ������� ���Ѵ�. 
		// ���� if�� ����, ��ġ�� ������ ��

		//break;

		// ĳ���Ͱ� Ư�� ��ġ�� �����ϸ� GameOver�� true �ٲ�鼭 ����ǰ� �ϱ�
		if (playerX == 2 && playerY == 18)	// ��Ʈ�� ��ǥ
		{
			GameOver = true;
		}

		if (GameOver)
		{
			break;
		}
	}
}