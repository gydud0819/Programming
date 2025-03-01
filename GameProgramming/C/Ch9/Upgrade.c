#include "Upgrade.h"

/*
* ���׷��̵� �ý����� �����.
* ������ ������ ������ ���� ���ݷ��� ������Ų��.
* ����, ���ݷ� ������ ����Ǿ�� �ұ�? -> ����Ǿ�� �Ѵ�.
* ����, ���ݷ� ���� -> ���� ���� ����. (C++ �ٸ� ���, C��� �ٸ� ���)
*/

int WeaponLv = 0;		// ������ ����
int NomalLv = 1;		// �⺻ ���ݷ�
int AdvanceLv = 0;		// ��ȭ�� ���� 

int BaseAP = 10;
int CurrentAP = 0;

void ShowUpgradeMenu()
{
	int NomalCost = 100;	// �⺻ ��ȭ�� �Ҹ�Ǵ� ���
	int HighCost = 500;		// ��� ��ȭ�� �Ҹ�Ǵ� ���

	while (true)
	{
		printf("------------------------------------\n");
		printf("1. ��ȭ�ϱ�\n");
		printf("2. ��� ���ü� �̿�\n");
		printf("3. ��ȭ �׸��ϱ�\n");
		printf("------------------------------------\n");

		int inputnumber = 0;

		scanf_s("%d", &inputnumber);
		while (getchar() != '\n');

		if (inputnumber == 1)
		{
				system("cls");		// system("cls");�� ����Ͽ� �ܼ�â�� ���������� �ʰ� �־��־���. 
			// ���� ���� ����Ѱ�?
			if (UseMoney(NomalCost))
			{
				WeaponUpgrade();
			}
		}
		else if (inputnumber == 2)
		{
				system("cls");
			// ���� ���� ����Ѱ�?
			if (UseMoney(HighCost))
			{
				HighUpgrade();		// ��� ��ȭ �Լ�
			}
		}
		else if (inputnumber == 3)
		{
			printf("��ȭ�� �����մϴ�.\n\n");
			break;
		}
		else
		{
			system("cls");
			printf("�߸��� �Է°��� �������ϴ�.\n");
			
		}
	}

}

void WeaponUpgrade() // ���� �⺻ ��ȭ �Լ�
{
	printf("���⸦ ��ȭ�մϴ�.\n");
	printf("------------------------------------\n");
		
	int Weight = 5;

	NomalLv = NomalLv + 1;
	CurrentAP = CurrentAP + BaseAP + Weight * WeaponLv;		// �� ���ݷ�

	WeaponLv = WeaponLv + NomalLv + AdvanceLv;				// ������ ���� = ���� ���� + �⺻ ���� + ��ȭ�� ����

	printf("���� ������ ���� : %d, ���� ������ ���ݷ� : %d\n", WeaponLv, CurrentAP);
	
}

void HighUpgrade()	// ���� ��� ��ȭ �Լ�
{
	printf("��� ��ȭ�� �̿��մϴ�.\n"); 
	printf("------------------------------------\n");

	int Weight = 50;

	AdvanceLv = AdvanceLv + 1;
	CurrentAP = CurrentAP + BaseAP + Weight * WeaponLv;

	WeaponLv = WeaponLv + NomalLv + AdvanceLv;

	printf("���� ������ ���� : %d, ���� ������ ���ݷ� : %d\n", WeaponLv, CurrentAP);
}
