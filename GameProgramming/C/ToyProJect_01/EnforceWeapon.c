#include "EnforceWeapon.h"

void ShowMenu()
{
	printf("1. ��ȭ�Ѵ�.\n");
	printf("2. ���� ���¸� Ȯ���Ѵ�.\n");

	int InPutNumber = 1;
	scanf_s("%d", &InPutNumber);
	while (getchar() != '\n');

	if (InPutNumber == 1)
	{
		// ��ȭ�Ѵ�.
		printf("��ȭ�Ѵ�.\n");	//Upgrade �Լ��� ��ü
	}
	else if (InPutNumber == 2)
	{
		// ���¸� Ȯ���Ѵ�.
		printf("���¸� Ȯ���Ѵ�.\n");		// ShowStatus �Լ��� ��ü
	}
	else
	{
		printf("�ش��ϴ� �Է°��� �������� �ʽ��ϴ�.\n");
		printf("�ùٸ� ���� �Է����ּ���.\n");
	}
	if (IsGameClear())
	{
		printf("������ Ŭ�����߽��ϴ�.\n");
	}
	else
	{
		printf("��ǥ ������ �޼����� ���߽��ϴ�.\n");
	}

	printf("��� �����Ϸ��� �ƹ� ��ư�� �����ּ���.\n");
	_getch();
	system("cls");
}

void Upgrade()
{

}

void ShowStatus()
{
	CurrentLevel++;
}

bool IsGameClear()
{
	// ���� ������
	// A ? B : C;
	// A ���ǽ��� True�̸� B�� ��ȯ False�̸� C�� ��ȯ
	return true;
}
