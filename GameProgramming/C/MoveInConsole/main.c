/*
* �ۼ���	: 2025-03-06 / 03-07
* �ۼ���	: ��ȿ��
* ����	: �ܼ�â�� �÷��̾ �����̵��� �����
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "MapBoder.h"
#include <conio.h>	// _kbhit() �Լ��� �� �� �ִ� �������
#include <stdlib.h>
#include "Random.h"

// Ŀ�� : OutPut ����� ����ϴ� ��ġ�� �ȳ����ִ� �ȳ� ��ȣ.

// 2��° ��ǥ : Ŀ�� �ű��

// Ŀ�� ��ġ �ű�� �Լ�
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

// Ŀ�� ���̴°� �����ϴ� �Լ�
//void HideCursor()
//{
//	CONSOLE_CURSOR_INFO info;
//	info.bVisible = false;
//	info.dwSize = 1;
//
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
//}

/*
* ���� ����
* �÷��̾��� ���� ��ġ�� �����ϱ�
* ��ǥ�� ���� ������ ������
* SetCurPos �Լ��� �̿��Ͽ� ���� ���ϴ� ��ġ�� �÷��̾� ��ġ�ϱ�
*/

// ��������
bool GameOver = false;	// bool �Լ��� ����Ͽ� �÷��̾ ��ü�� ������ ����ǰ� �ϱ�
int Currentscore = 0;
int randomX = 18;
int randomY = 1;
int playTime = 0;

int questItemPosX = 34;
int questItemPosY = 5;
bool isQuest = false;

int main()
{
	// 1��° �̽� : " "(���鹮��)�� ���� ���� ũ�Ⱑ �ٸ���. �� = " " x2
	// 2��° �̽� : �÷��̾ �� �ȿ� �ֵ��� �ϰ������ �� �ٱ��� �ִ�.

	
	ShowBoder();
	CreateRandomSeed();

	SetCurPosition(randomX, randomY);
	printf("��");

	SetCurPosition(questItemPosX, questItemPosY);
	printf("��");

	SetCursorVisble(false);

	// �÷��̾��� ���� ��ǥ�� �������ִ� ���� �����ϱ�

	int playerX = 10;	// x�� �� +2 (== 1ĭ�̵�)
	int playerY = 1;	// y�� �� +1 �ϸ� ��ĭ�� ������ ��������. ���δ� -1


	// �÷��̾ ó�� ������ �� �����ϴ� �� �����

	//HideCursor();
	SetCurPosition(playerX, playerY);
	printf("��");	// ���� Ŀ�� ��ġ�� "" ���ڸ� ����Ѵ�.

	
	
	// ������ �ٷ� ������� �ʵ��� loop �����
	// �ݺ������� ����Ǵ� �κ�
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

		//system("cls");	// �ܻ��� ���� �ʰ� ����. (�Ҿ����� �ڵ�) -> �̰� ���� ��ü�� ��������.
		//ShowBoder();
		SetCurPosition(playerX, playerY);
		printf("��");

		// UI �ڵ�
		SetCurPosition(65, 0);
		printf("Score");

		SetCurPosition(65, 1);
		printf("���� ���� : %d", Currentscore);

		while (true)
		{
			// �ð� ���� �ڵ�
			playTime++;
			//int hour = playTime / 360;
			int minute = playTime / 60;
			int second = playTime % 60;

			SetCurPosition(65, 2);
			printf("�÷��� �ð� : %02d : %02d", minute, second);

			Sleep(1000);
		}

		if (isQuest)
		{
			SetCurPosition(65, 3);
			printf("����Ʈ�� Ȱ��ȭ �Ǿ����ϴ�!");
		}

		Sleep(50); 


		// 1. Wait InputKey (Ư�� Ű�� ������ ��)
		// 2. playerX, playerY ���� ��ȭ��Ų��.
		// 3. �ش� ��ǥ�� Ŀ���� ��ġ�� �ٲٰ� ����Ѵ�.

		// ����� ���ϰ� �ϴ¹��
		// �÷��̾�� ���̶� ��ġ�� �������� ������� ���Ѵ�. 
		// ���� if�� ����, ��ġ�� ������ ��

		//break;

		// ĳ���Ͱ� Ư�� ��ġ�� �����ϸ� GameOver�� true �ٲ�鼭 ����ǰ� �ϱ�
		if (playerX == randomX && playerY == randomY)	// �����۰� �÷��̾��� ��ġ�� ���� ��Ȳ
		{
			Currentscore++; // 1. Ư�� ��ǥ�� ���� ������ ������ ������.
			// 2. �������� ��ġ�� ����Ǿ�� �Ѵ�. (��ǥ�� �ٲ۴�.)
			randomX = ReturnPosX();
			randomY = ReturnPosY();
			SetCurPosition(randomX, randomY);
			printf("��");
		}

		if (playerX == questItemPosX && playerY == questItemPosY)
		{
			isQuest = true;
		}

		if (Currentscore == 10)
		{
			break;
		}
	}
}