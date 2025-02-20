/*
* �ۼ���	: 2025-02-19
* �ۼ���	: ��ȿ��
* ����	: ������ �ǽ�
*/

/*
* ��Ģ����	: +, - , * ,/, %
*
* ���� ������
* ��ȣ : +, -	����, ���	-10, +10
*
* ���� ������
* num1+num2
* ���� 2��������
*
* ���� ������
* ? 1�� : = 2�� : 3��
*/

/*
* �������� ���ӻ�
* ��� ������: +, - , *, /, %
* �� ������: > , <, ==
* ��Ʈ ������: (data type)�� ��� �� �� ����
* ���� ������: (or, and ||, &&)
*
*
*/
/*
* �� ������ ��� : ��(true) 1, ����(false) 0
* 1, 0 : 1 + 0 = 1;
*/


/*
* 
* �ý��� ����
* "" Ŀ���� ���� (�����ڰ� ���� ���� ������ �������ڴ�)
* 
* 
* #include	<>	1. ������ ��������
* #include	""	2. ū ����ǥ�� ��������
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	//��Ģ���� + ������

	printf("������ �ǽ�\n\n");

	// ������ ���� �ʱ�ȭ

	int num1 = 10;
	int num2 = 3;

	//����
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	//����
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	//����
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	//������
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	//������
	printf("%d %% %d = %d\n\n", num1, num2, num1 % num2); //%�� 2�� �����

	printf("-------------------------------------------------------------------\n\n");

	printf("�ǽ� 2 \n\n");

	printf("�� ��� num1 > num2 : %d\n", num1 > num2); // �� == true

	printf("�� ��� num1 < num2 : %d\n\n", num1 < num2); // ���� == false


	printf("-------------------------------------------------------------------\n\n");

	printf("�ǽ� 3: ���� ������\n\n");

	bool isTrue = true;	//0 �Ǵ� 1�� ������� ������
	bool isFalse = false;

	int result1 = num1 < num2;

	printf("���� ������ ��� ��� : %s\n", result1 ? "true" : "false");
	printf("���� ������ ��� ��� : %d\n\n", result1 ? 1 : 0);

	printf("-------------------------------------------------------------------\n\n");

	printf("�ǽ� 4: ���� ������ \n\n");


	//	!num2 : num2�� �ƴϴ� (!�� ����)	fasle -> true // true -> false

	printf("���� ������ : %d\n", (num1 == num2) || (num1 < num2));	//num1 != num2 �� ���� �ٸ� ��
	printf("���� ������ : %d\n\n", (num1 != num2) && (num1 > num2));	//num1 != num2 �� ���� �ٸ� ��

	printf("-------------------------------------------------------------------\n\n");

	printf("�ǽ� 5 : ���� ������ \n\n");

	int num3 = 2;
	int num4 = 5;
	num3 += num4;		//num3 <- 2 + 5 = 7


	//T = T + A
	//T += A

	printf("num3 + num4�� �� : %d\n\n", num3);

	printf("-------------------------------------------------------------------\n\n");

	printf("�ǽ� 6 : ���� ������, ���� ������\n\n");

	//	���� ������ : ������ ���� ó���� �Ŀ� ������ �Ѵ�.
	//	num3�� �� : 2 ��� -> num3++ : num3 += 1;

	//	���� ������ : ����� ����� ���忡 �����Ѵ�.
	//	num4 += 1; -> printf ������ ó���Ѵ�.

	printf("num3�� �� : %d\n", num3++);
	printf("num3�� �� : %d\n", num3);
	printf("num4�� �� : %d\n", ++num4);
	printf("num4�� �� : %d\n\n", num4);

	//	|, &, <<, >> '��Ʈ' <- ���߿� ��� ����

	printf("-------------------------------------------------------------------\n\n");

	//���� ���丮1

	//���⸦ ��ȭ�ϴµ�
	//n���� ���� ����, n+1 ������ ������ ȭ�鿡 ����ϴ� ���丮�� �ۼ��غ���

	//����
	//0�� - �⺻ ���ݷ� = 5;
	//1�� - ��ȭ�� ���ݷ� = 7;
	
	//AP = BP + WL * GP; �Ѱ� = �⺻ ���ݷ� + ���� ���� * ���� ���

	

	int baseattack = 10;
	int weaponLv = 1;
	int weight = 2;

	int attackpower = baseattack + weaponLv * weight;
	
	printf("������ ���� : %d, ������ ���ݷ� : %d\n", ++weaponLv, attackpower);

	attackpower = baseattack + weaponLv * weight;
	printf("������ ���� : %d, ������ ���ݷ� : %d\n\n", weaponLv++, attackpower);

	printf("-------------------------------------------------------------------\n\n");

		
	//���� ���丮2
	
	// ������ �κ��丮 -> slot. ��Ÿ ������ ������ stack x ����
	// slot�� �ִ� ���� : ����
	// stack�� �ִ� ���� : ����
	// A �������� n�� ȹ��, B ������ m�� ȹ��
	//���� �κ��丮�� ������ ����á���� ��á���� ǥ���ϴ� ����� ǥ���غ��� 

	// 3�� ������ �̿��ؼ� �غ���

	int maxInventorySlot = 10;
	int AStackCount = 200;
	int BStackCount = 200;
	int ADrop = 555;
	int BDrop = 9999;

	printf("1�ð� ���� ����� �ؼ� �������� ȹ���� �ߴ�.\n");
	printf("A������ : %d��, B������ : %d���� ȹ���ߴ�.\n", ADrop, BDrop);

	// ������

	int AInventoryCount = (ADrop % AStackCount) == 0 ? (ADrop / AStackCount) : (ADrop / AStackCount) + 1;
	int BInventoryCount = (BDrop % BStackCount) == 0 ? (BDrop / BStackCount) : (BDrop / BStackCount) + 1;

	printf("A�� ���� : %d��, B�� ���� : %d��\n", AInventoryCount, BInventoryCount);
	printf("��� : %s\n", maxInventorySlot <= (AInventoryCount + BInventoryCount) ? "������" : "�������");
}
