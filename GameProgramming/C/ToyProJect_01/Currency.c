#include <stdio.h>
#include <stdbool.h>
#include "Currency.h"


bool CanUpgrade(int Cost)
{
	if (Cost < CurrentMoney)
	{
		CurrentMoney -= Cost;
		printf("���� ������ : %d\n", CurrentMoney);
		return true;

	}
	else
	{
		printf("Game Over�Ф� ��� ���� �� ����߾���\n");
		IsFail = true;
	}
}