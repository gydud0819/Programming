/*
* menu.h �ڵ带 ctrl +c , v
*/
#include "menu.h"

void SelectMenu()
{
	while (true)
	{
		system("cls");
		printf("1. ��ȭ�Ѵ�.\n");
		printf("2. �׸��д�.\n");
		printf("3. ���α׷� ����.\n");

		int inputNumber = 1;
		scanf_s("%d", &inputNumber); //����� ���۰� �ν����� �ʴ´� '\n' <- ����Ѵ�.
		while (getchar() != '\n');	// character �Է� ���� 

		if (inputNumber == 1)
		{
			Upgrade();
		}
		else if (inputNumber == 2)
		{
			printf("��ȭ�� �׸��Ӵϴ�.\n");
		}
		else if (inputNumber == 3)
		{
			printf("��ȭ�� �����մϴ�.\n");
			break;
		}
		else
		{
			printf("�߸��� ���� �Է��߽��ϴ�.\n");
		}

		// �÷��̾ Ư��Ű�� �Է����� �� �Ѿ���� �����ϱ�

		printf("��� ������ �Ϸ��� �ƹ� Ű�� �Է��ϼ���.\n");
		_getch();	// �Է� ���� �޾ƿ��� ��ɾ�
	}
}
