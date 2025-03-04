#include <stdio.h>
#include <stdbool.h>
#include "Currency.h"


bool CanUpgrade(int Cost)
{
	if (Cost < CurrentMoney)
	{
		CurrentMoney -= Cost;
		printf("현재 소지금 : %d\n", CurrentMoney);
		return true;

	}
	else
	{
		printf("Game Overㅠㅠ 모든 돈을 다 사용했어요ㅠ\n");
		IsFail = true;
	}
}