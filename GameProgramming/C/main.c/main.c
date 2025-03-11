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
#include "Console.h"

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

extern int map[20][20];	// �̷��� ũ�� 

int itemCount = 0;	// ������ ����

bool Exit = false;	// bool �Լ��� ����Ͽ� �������� �� ������ �ⱸ�� Ȱ��ȭ �ǵ��� �ߴ�.
int exitX = 19;		// �ⱸ�� X ��ǥ
int exitY = 18;		// �ⱸ�� Y ��ǥ

int main()
{
	ShowMap();
	HideCursor();

	int playerX = 10;	// �÷��̾��� ���� ��ġ
	int playerY = 1;	// �÷��̾��� ���� ��ġ

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

		if (itemCount == 4)	// �������� �� ������ �ⱸ�� �����ȴ�.
		{
			
			map[exitY][exitX] = 0;
			SetCurPosition(25, 0);
			printf("�ⱸ�� Ȱ��ȭ �Ǿ����ϴ�!");
			ShowMap();	// �ⱸ�� �����ϱ� ���� �� �ٽ� �׸��� �� �Լ��� �ѹ� �� ����ߴ�.
			
		}

		SetCurPosition(playerX, playerY);
		SetColor(0, 2);
		printf("��");
		SetColor(0, 15);


		Sleep(100);

		
		if(Exit)
		{
			system("cls");
			SetCurPosition(25, 10);
			SetColor(0, 4);
			printf("Game Celar!");	// �ⱸ�� ������ Game Clear�� �߸鼭 ���ᰡ �ȴ�.

			break;
		}

	}
}




