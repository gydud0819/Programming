#include "Upgrade.h"

/*
* 업그레이드 시스템을 만든다.
* 무기의 레벨과 레벨에 따른 공격력을 증가시킨다.
* 레벨, 공격력 정보가 저장되어야 할까? -> 저장되어야 한다.
* 레벨, 공격력 정보 -> 전역 변수 선언. (C++ 다른 방식, C언어 다른 방식)
*/

int WeaponLv = 0;
int NomalLv = 1;
int AdvanceLv = 0;

int BaseAP = 10;
int CurrentAP = 0;

void ShowUpgradeMenu()
{
	while (true)
	{
		printf("1. 강화하기\n");
		printf("2. 고급 제련소 이용\n");
		printf("3. 강화 그만하기\n");

		int inputnumber = 0;
		scanf_s("%d", &inputnumber);
		while (getchar() != '\n');

		if (inputnumber == 1)
		{
			WeaponUpgrade();
			
		}
		else if (inputnumber == 2)
		{
			HighUpgrade();
			
		}
		else if (inputnumber == 3)
		{
			printf("강화를 종료합니다.\n");
			break;
		}
		else
		{
			printf("잘못된 입력값을 눌렀습니다.\n");
		}
	}

}

void WeaponUpgrade()
{
	printf("무기를 강화합니다.\n");
		
	int Weight = 5;

	NomalLv = NomalLv + 1;
	CurrentAP = CurrentAP + BaseAP + Weight * WeaponLv;

	WeaponLv = WeaponLv + NomalLv + AdvanceLv;

	printf("현재 무기의 레벨 : %d, 현재 무기의 공격력 : %d\n", WeaponLv, CurrentAP);
}

void HighUpgrade()
{
	printf("고급 강화를 이용합니다.\n");

	int Weight = 50;

	AdvanceLv = AdvanceLv + 1;
	CurrentAP = CurrentAP + BaseAP + Weight * WeaponLv;

	WeaponLv = WeaponLv + NomalLv + AdvanceLv;

	printf("현재 무기의 레벨 : %d, 현재 무기의 공격력 : %d\n", WeaponLv, CurrentAP);
}
