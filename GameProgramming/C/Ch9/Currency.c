#include "Currency.h"

bool IsMoneyEnough(int amount) // ������ üũ�ϴ� �Լ�
{
	return CurrentMoney >= amount ? true : false;
	// 1. ���� ������ A ? B : c;
	// A ���� : �� -> B, ���� -> C
	// return true // false;


	/*if (currentMoney >= amount)
	{
		true;
	}
	else
	{
		false;
	}*/
}

bool UseMoney(int price)
{
	if (IsMoneyEnough(price))
	{
		CurrentMoney = CurrentMoney - price;
		ShowInfo();
		return true;
	}
	else
	{
		printf("��ȭ�� �����մϴ�.\n");
		return false;
	}
}
