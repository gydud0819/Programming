#include "Upgrade.h"

/*
* 업그레이드 시스템을 만든다.
* 무기의 레벨과 레벨에 따른 공격력을 증가시킨다.
* 레벨, 공격력 정보가 저장되어야 할까? -> 저장되어야 한다.
* 레벨, 공격력 정보 -> 전역 변수 선언. (C++ 다른 방식, C언어 다른 방식)
*/

int WeaponLv = 0;		// 무기의 레벨
int NomalLv = 1;		// 기본 공격력
int AdvanceLv = 0;		// 강화된 레벨 

int BaseAP = 10;
int CurrentAP = 0;

void ShowUpgradeMenu()
{
	int NomalCost = 100;	// 기본 강화시 소모되는 비용
	int HighCost = 500;		// 고급 강화시 소모되는 비용

	while (true)
	{
		printf("------------------------------------\n");
		printf("1. 강화하기\n");
		printf("2. 고급 제련소 이용\n");
		printf("3. 강화 그만하기\n");
		printf("------------------------------------\n");

		int inputnumber = 0;

		scanf_s("%d", &inputnumber);
		while (getchar() != '\n');

		if (inputnumber == 1)
		{
				system("cls");		// system("cls");을 사용하여 콘솔창이 지저분하지 않게 넣어주었다. 
			// 현재 돈이 충분한가?
			if (UseMoney(NomalCost))
			{
				WeaponUpgrade();
			}
		}
		else if (inputnumber == 2)
		{
				system("cls");
			// 현재 돈이 충분한가?
			if (UseMoney(HighCost))
			{
				HighUpgrade();		// 고급 강화 함수
			}
		}
		else if (inputnumber == 3)
		{
			printf("강화를 종료합니다.\n\n");
			break;
		}
		else
		{
			system("cls");
			printf("잘못된 입력값을 눌렀습니다.\n");
			
		}
	}

}

void WeaponUpgrade() // 무기 기본 강화 함수
{
	printf("무기를 강화합니다.\n");
	printf("------------------------------------\n");
		
	int Weight = 5;

	NomalLv = NomalLv + 1;
	CurrentAP = CurrentAP + BaseAP + Weight * WeaponLv;		// 총 공격력

	WeaponLv = WeaponLv + NomalLv + AdvanceLv;				// 무기의 레벨 = 무기 레벨 + 기본 레벨 + 강화된 레벨

	printf("현재 무기의 레벨 : %d, 현재 무기의 공격력 : %d\n", WeaponLv, CurrentAP);
	
}

void HighUpgrade()	// 무기 고급 강화 함수
{
	printf("고급 강화를 이용합니다.\n"); 
	printf("------------------------------------\n");

	int Weight = 50;

	AdvanceLv = AdvanceLv + 1;
	CurrentAP = CurrentAP + BaseAP + Weight * WeaponLv;

	WeaponLv = WeaponLv + NomalLv + AdvanceLv;

	printf("현재 무기의 레벨 : %d, 현재 무기의 공격력 : %d\n", WeaponLv, CurrentAP);
}
