#include "EnforceWeapon.h"

void ShowMenu()
{
	printf("1. ��ȭ�Ѵ�.\n");
	printf("2. ���� ���¸� Ȯ���Ѵ�.\n");

	int InPutNumber = -1;
	scanf_s("%d", &InPutNumber);
	while (getchar() != '\n');

	if (InPutNumber == 1)
	{
		// ��ȭ�Ѵ�.
		//printf("��ȭ�Ѵ�.\n");	//Upgrade �Լ��� ��ü
		Upgrade();

	}
	else if (InPutNumber == 2)
	{
		// ���¸� Ȯ���Ѵ�.
		printf("���¸� Ȯ���մϴ�!\n");		// ShowStatus �Լ��� ��ü
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
}

void ShowStatus()
{
	
}

// ���� ���� ���� == �ִ� ����
bool IsGameClear()
{
	// ���� ������
	// A ? B : C;
	// A ���ǽ��� True�̸� B�� ��ȯ False�̸� C�� ��ȯ
	return CurrentLevel == TargetLevel ? true : false;
}
