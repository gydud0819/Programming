#include "Random.h"

// 1 ~ 100���� ���� ���� ��ȯ
int ReturnRandomValue()
{
	srand((unsigned int) time(NULL) * 1000 + clock());	// �ð�

	// reversePercent

	//int randomValue = (rand() % 100) + 1;	// return�� �����ؼ� ��ȯ�� �Ŷ� ����.
	return (rand() % 100) + 1;
}

bool CheckRandomFunc(int Percent)
{
	int randValue = ReturnRandomValue();		// 1 ~ 100 �������� ��ȯ

	int SuccessPercent = Percent;				// ����Ȯ��

	if (randValue <= Percent)
	{
		printf("�����Ͽ����ϴ�! %d\n", randValue);		
		return true;		 
	}						 
	else					 
	{						 
		printf("�����Ͽ����ϴ٤Ф� %d\n", randValue);
		return false;
	}

}

//int ReturnRandomInRange(int min, int max)
//{
//	srand((unsigned int) (time(NULL) * 1000 + clock()));
//
//	return (rand() % (max - min + 1)) + min;		
//}
