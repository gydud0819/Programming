#include "Currency.h"

bool IsMoneyEnough(int amount) // 조건을 체크하는 함수
{
	return CurrentMoney >= amount ? true : false;
	// 1. 삼항 연산자 A ? B : c;
	// A 조건 : 참 -> B, 거짓 -> C
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
		printf("재화가 부족합니다.\n");
		return false;
	}
}
