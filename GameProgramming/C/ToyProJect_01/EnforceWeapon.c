#include "EnforceWeapon.h"

void ShowMenu()
{
	printf("1. ��ȭ�� �մϴ�!\n");
	printf("2. ���� ���¸� Ȯ���մϴ�!\n");

	int InPutNumber = -1;
	scanf_s("%d", &InPutNumber);
	while (getchar() != '\n');

	if (InPutNumber == 1)
	{
		// ���׷��̵� ����� �����Ѵ�.
		if (CanUpgrade(UpgradeCost))
		{
			if (CheckRandomFunc((50)))	// 90% ����
			{
				Upgrade();
			}
			else						// ����
			
			{
				printf("��ȭ�� �����߽��ϴ٤Ф�\n");
			}

		}

		ShowStatus();



		// ��ȭ�Ѵ�.
		//printf("��ȭ�Ѵ�.\n");	//Upgrade �Լ��� ��ü


	}
	else if (InPutNumber == 2)
	{
		// ���¸� Ȯ���Ѵ�.
		//printf("���¸� Ȯ���մϴ�!\n");		// ShowStatus �Լ��� ��ü
		ShowStatus();
	}
	else
	{
		// �߸��� �� �Է�
		printf("�ش��ϴ� �Է°��� �������� �ʾƿ�Ф�\n");
		printf("�ùٸ� ���� �Է����ּ���!\n");
	}

	// ���� Ŭ���� ���� Ȯ��
	if (IsGameClear())
	{
		//printf("������ Ŭ�����߽��ϴ�.\n");
		IsClear = true;
	}
	else
	{
		printf("��ǥ ������ �޼����� ���߽��ϴ٤Ф�\n");
	}

	printf("��� �����Ϸ��� �ƹ� ��ư�� �����ּ���!\n");
	_getch();
	system("cls");
}

void Upgrade()
{
	// CurrentLevel = CurrentLevel + 1;
	CurrentLevel++;

	printf("��ȭ�� �����߽��ϴ�!\n");
}

void ShowStatus()
{
	printf("���� ���� ���� : %dLv\n", CurrentLevel);
	// ���� ������ �ݾ�
	printf("���� ���� �ݾ� : %d��\n", CurrentMoney);
}

// ���� ���� ���� == �ִ� ����
bool IsGameClear()
{
	// ���� ������
	// A ? B : C;
	// A ���ǽ��� True�̸� B�� ��ȯ False�̸� C�� ��ȯ
	return CurrentLevel == TargetLevel ? true : false;
}
