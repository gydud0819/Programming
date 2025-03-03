#include "Play.h"
#include <stdbool.h>

// ��ȭ ���ӿ� �ʿ��� ���� ������
// ���� ��ǥ
int CurrentLevel = 8;
int TargetLevel = 10;
bool IsClear = true;

bool IsFail = false;

void ShowTitle()
{
	printf("������ �ε����Դϴ�.......\n");
	printf("================================\n");
	printf("================================\n");
	printf("================================\n\n");

	printf("	���� ��ȭ�ϱ�		\n\n");
}

void ShowManual()
{
	// 1. ���� ���
	printf("���� ���\n\n");
	printf("Ű���� �Է� �� ����Ű�� ������ �����Ѵ�.\n");
	printf("�Է� ���� �̿��� Ű�� ������ �缱���� �Ѵ�.\n\n");

	// 2. ���� ��ǥ
	printf("���� ��ǥ\n\n");
	printf("���� 10�� �����\n\n");

	// 3. ���� ���
	printf("���� �÷��� ���\n\n");
	printf("1. ���ѵ� ���������� ��ǥ�� �޼��ؾ� �Ѵ�.\n");
	printf("2. Ư�� ���ⷹ������ ��ȭ �ϰ��� �����Ѵ�.\n");
	printf("3. Ư�� �������� ���Ⱑ �ı��ȴ�.\n\n");
}

void GameLogic()
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

		if (IsClear)
		{
			// ���� Ŭ����
			//printf("Game Clear\n");
			IsClear = true;
		}
		if (IsFail)
		{
			// ���� ����
			printf("Game Over\n");
		}

	}
}

void GameLoop()
{
	ShowTitle();
	ShowManual();
	GameLogic();
}
