#include "Intro.h"
#include <stdbool.h>

void IntroMenu()
{
	while (true)
	{
		// UI �ؽ�Ʈ
		printf("1. ���ӽ���\n");
		printf("2. ��������\n");

		// ����
		// �Է����� �����ϴ� ���
		// ������ ���� ���ؼ� �����Ѵ�.
		int InputNumber = 1;			// �Է¹��� ���� �̸�
		scanf_s("%d", &InputNumber);	// �Է¹޴� �Լ� (stdio.h)
		while (getchar() != '\n');		// �Է� ���۸� ���� ���� �ڵ�

		// �� ������ '==' -> ���ǹ��� �Բ� ����Ѵ�.
		if (InputNumber == 1)
		{
			// ���� ����
			GameLoop();
		}
		else if (InputNumber == 2)
		{
			// ���� ����
			break;
		}
		else
		{
			// �߸��� ���� �Է��ߴ�.
			// printf("�߸��� ���� �Է��߽��ϴ�.\n");
		}
	}
}
