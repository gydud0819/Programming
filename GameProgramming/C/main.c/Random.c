#include "Random.h"

void ItemRandomSeed()
{
	// �������� ������ �� ���� �������� ��ġ�� �Ǿ�� �Ѵ�.
	srand(time(NULL) % 20);
}

int ItemPosX()
{
	int randValue = rand() % 20 + 2;
	return randValue % 2 == 0 ? randValue : randValue + 2;
}

int ItemPosY()
{
	int randValue = rand() % 20;
	return randValue;
}
