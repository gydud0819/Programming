#include "Random.h"

void CreateRandomSeed()
{
	srand(time(NULL) * 1000 + clock());		// ���� ������ �ð��� �����ִ� �ڵ�
}

int ReturnPosX()
{
	 
	// 0 ~ 40 
	// ������ + ¦���� ��ȯ�ؾ� �Ѵ�.
	
	// 1. ������ ���ڸ� �̴´�. - rand �Լ��� ����ؼ� A ~ B ����
	// 2. 1 ~20 *2 (¦��)
	// �Ѵ� ����ص� �ǰ� �� �� �����ϱ� ���� �ɷ� �����Ѵ�.
	// �� �ڵ��߿� �� ȿ������ �ڵ带 ����Ѵ�. (���⿡ ���ų�, �޸� ����ȭ�� ���� ��)

	int randValue = rand() % 36 + 1;	// 1~40���� ����Ѵ�.
	return randValue % 2 == 0 ? randValue : randValue + 1;
}

int ReturnPosY()
{
	int randvalue = rand() % 18 + 1;
	return randvalue;
}
