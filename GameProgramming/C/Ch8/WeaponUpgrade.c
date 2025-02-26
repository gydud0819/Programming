#include "menu.h"
#include "WeaponUpgrade.h"

int WeaponLv = 1;
int BasicAttack = 10;
int Weight = 5;
int CurrentAttackPower = 0;

void Upgrade()
{
	// 강화를 무조건 성공하는 case
	// 무기의 레벨을 1상승 시킵니다.
	WeaponLv = WeaponLv + 1;
	// 현재 공격력 = 기본 공격력 + 레벨 * 가중치
	CurrentAttackPower = BasicAttack + WeaponLv * Weight;
	// printf("현재 공격력, 레벨");
	printf("현재 공격력은 %d, 무기의 레벨은 %d입니다.\n", CurrentAttackPower, WeaponLv);
}
