#include "menu.h"
#include "WeaponUpgrade.h"

int WeaponLv = 1;
int BasicAttack = 10;
int Weight = 5;
int CurrentAttackPower = 0;

void Upgrade()
{
	// ��ȭ�� ������ �����ϴ� case
	// ������ ������ 1��� ��ŵ�ϴ�.
	WeaponLv = WeaponLv + 1;
	// ���� ���ݷ� = �⺻ ���ݷ� + ���� * ����ġ
	CurrentAttackPower = BasicAttack + WeaponLv * Weight;
	// printf("���� ���ݷ�, ����");
	printf("���� ���ݷ��� %d, ������ ������ %d�Դϴ�.\n", CurrentAttackPower, WeaponLv);
}
