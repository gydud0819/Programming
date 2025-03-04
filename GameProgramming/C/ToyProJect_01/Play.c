#include "Play.h"
#include <stdbool.h>

// ��ȭ ���ӿ� �ʿ��� ���� ������
// ���� ��ǥ
int CurrentLevel = 0;	// ���� ����
int TargetLevel  = 10;	// ��ǥ ����
bool IsClear = false;

// ���� ���� - ��ȭ
int CurrentMoney = 10000;
int UpgradeCost = 1000;
bool IsFail = false;	// ��ȭ�� ���� ���� �� ��

void ShowTitle()
{
	printf("������ �ε����Դϴ�.......\n");
	printf("================================\n");
	printf("================================\n");
	printf("================================\n\n");

	printf("���� ��ȭ ������ �����մϴ�! >3<	\n\n");
	printf("--------------------------------\n");
}

void ShowManual()
{
	// 1. ���� ���
	printf("	<���� ���>\n\n");
	printf("1. Ű���� �Է� �� ����Ű�� ������ �����մϴ�!\n");
	printf("2. �Է� ���� �̿��� Ű�� ������ �缱���� �մϴ�!\n\n");

	printf("--------------------------------\n");

	// 2. ���� ��ǥ
	printf("	<���� ��ǥ>\n\n");
	printf("�� ���� 10�� ����� ��\n\n");

	printf("--------------------------------\n");

	// 3. ���� ���
	printf("	<���� �÷��� ���>\n\n");
	printf("1. ������ ��ȭ�� ��ǥ�� �޼��ؾ� �ؿ�!\n");
	printf("2. Ư�� �������� ��ȭ�� ������ �ϰ��� ���� �־��!\n");
	printf("3. Ư�� �������� ���Ⱑ �ı��� ���� �־��!\n\n");

	printf("--------------------------------\n");
}

void GameLogic()	// EnforceWeapon.h
{
	while (true)
	{
		// �޴� ���� ��ȯ
		ShowMenu();		// EnforceWeapon.h �� ���ԵǾ� �ִ�.

		// ������ Ŭ���� �߰ų� ���ӿ����� ���� ��
		if (IsClear || IsFail)
		{
			break;
		}

	}

	if (IsClear)
	{
		// ���� Ŭ����
		printf("Game Clear��\n");
		
	}
	if (IsFail)
	{
		// ���� ����
		printf("Game Over...??\n");
	}
}

void GameLoop()
{
	ShowTitle();
	ShowManual();
	GameLogic();
}
