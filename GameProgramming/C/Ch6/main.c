/*
* �ۼ���	: 2025-02-24
* �ۼ���	: ��ȿ��
* ����	: �ڵ��� �帧�� ���� - ���ǹ�, �ݺ���
*/

/*
* main �Լ��� ���α׷��� �������̴�.
* �ڵ�� ���������� ������� ����ȴ�.
* main �Լ��� ������ �߰�ȣ�� ������ ���α׷��� ����ȴ�.
*/

/*
* ����� : ���α׷��� �ߴܽ��Ѽ� �ڵ带 Ȯ���ϴ� ���
* f9�� ������ �ߴ��������� �Ǵ� ������ �� �ִ�.
*/

/*
* ���ǹ� (�б⹮), branch
* if ����
* if(){}	// ���ǹ�
* () : ����
* {} : ��ü, body
* 
* ������ ��
* if(); {}	//�����ݷ��� �Ұ�ȣ �ڿ� ���� ��
* - ���ǹ��� ������� �ڵ尡 ����ȴ�.
*/

/*
* if(����1)
* ¦�� : n % 2 == 0 (� �� n�� ������ �� 0�̵Ǹ� ¦��)
* Ȧ�� : n % 2 == 1
* 
* else // if�� ������ ������ ��� �͵�
*/

/*
* ������ �������� ���� ���� �̻��̸� "N"����� �ű�� �ý����� �����.
* ���� >= 100	: S����̴�.
* ���� >= 90		: A����̴�.
* ���� < 90		: F����̴�.
* 
*/

/*
* ����
* 
* �ڵ��� �帧 ���� -> ���ǿ� ���� Ư�� �κи� �����ϴ� ���
* if(true) {} ���� false �������� �ʴ´�
* 
* (false && true)	(false || true) // �÷��̾� ������ �� ���� ����.
*/

#include <stdio.h>
#include <stdlib.h>		
#include <time.h>

int main()
{
	printf("���ǹ� ����1\n\n");

	//int : 4����Ʈ ũ���� ������ ������ �����ϰڴ�.

	int count = 15;

	// if�� ����
	// ���� ������, �� ������
	// 5 10

	// if ~ else ��
	if (count < 10)	// if���� ������ �� �� ;�� ������ �ʴ´�. true, false�� ��Ÿ����.
	{
		printf("count���� 10���� �۽��ϴ�.\n");
	}
	else
	{
		printf("count���� 10���� Ů�ϴ�.\n\n");
	}

	// if ~ else if ~ else ��
	printf("���� ����1\n\n");

	int score = 89;

	if (score >= 100)
	{
		printf("S���, ���� ���� : %d\n", score);
	}
	else if (score >= 90)
	{
		printf("A���, ���� ���� : %d\n", score);
	}
	else
	{
		printf("F���, ���� ���� : %d\n", score);
	}

	// ���� ����
	// ������ ���� 
	// ���ۿ� C��� �������� �������� ��� �˻�
	// ���ǹ� Ȯ��
	// ���� �Է��� ���ڿ� ���ϱ�
	// ũ�� -> Ů�ϴ�.

	// ���ڰ� �ִ�.
	// ���ǹ����� ���ؼ� ���ڰ� ū�� ������ ���Ѵ�.

	printf("----------------\n");

	
	// seed��

	printf("���� ���� ���߱� ����\n");
	printf("������ ���� : 0 ~ 100\n");

	srand(time(NULL));

	int randomNumber = rand() % 101;

	printf("��� �� : %d\n", randomNumber);

	int userValue = 0;

	scanf_s("%d", &userValue);

	//printf("������ �� : %d\n", userValue);

	if (userValue > randomNumber)
	{
		printf("��ǥ ������ Ů�ϴ�.\n");
	}
	else if (userValue < randomNumber)
	{
		printf("��ǥ ������ �۽��ϴ�.\n");
	}
	else
	{
		printf("�����Դϴ�!\n");
	}

	// ���� ����2
	// ���� ���߱� ���ӿ��� ������ ���� Ƚ���� ���� ��ŷ�� �ο��غ��� ������

	// if ~ else if ~ else if ~ else if

	int countNumber = 1;

	if (countNumber == 1)
	{
		printf("S��ũ �Դϴ�.\n");
	}
	else if (countNumber == 2)
	{
		printf("A��ũ �Դϴ�.\n");
	}
	else if (countNumber == 3)
	{
		printf("B��ũ �Դϴ�.\n");
	}
	else if (countNumber == 4)
	{
		printf("C��ũ �Դϴ�.\n\n");
	}

	printf("----------------\n");

	//switch��

	printf("switch ����\n\n");

	switch (countNumber)
	{
		case 1:
			printf("S��ũ �Դϴ�.\n");
			break;
		case 2:
			printf("A��ũ �Դϴ�.\n");
			break;
		case 3:
			printf("B��ũ �Դϴ�.\n");
			break;
		case 4:
			printf("C��ũ �Դϴ�.\n");
			break;
	}

	// ���� �� ��ŷ, Ƚ�� ���� ��ŷ
	// ��ŷ�� �ο��� �� �ִ� ���丮 �ۼ��ϱ�
	// 

	printf("----------------\n");
	

	printf("�ζ� ��ȣ ������\n");
	printf("�ζ��� �ִ� ��ȣ ���� : 45\n");

	int max = 45;
	int randomNumber2 = 6;

	srand(time(NULL));

	int userNumber;
	
	for (int i = 1; i <= 6; i++)
	{
		scanf_s("%d", &userNumber);
		printf("������ ��ȣ : %d", max % randomNumber2);
	}

	/*if (randomNumber2 < max)
	{
		randomNumber2 = (rand () % max) + 1;
		printf("%d\n", randomNumber2);
	}*/

	return 0;
}

// if (count < 10); => if(count < 10){}
// �����ݷ��� ���̸� �ڵ带 �ٸ��� �ν��Ͽ� 2���� �Ǿ� ������ �ȴ�.
