/*
* �ۼ���	: 2025-02-28
* �ۼ���	: ��ȿ��
* ����	: �Լ��� ����
*/

/*
* �Լ� : input ���� output ��ȯ(����)�Ѵ�.
*			A			B
* A �����͸� ��򰡿� �����Ͽ� B��� ��������� ��ȯ�Ѵ�.
* A, B ����	: �����ϱ� ���ؼ� ���� ����, ��ȯ�ϱ� ���ؼ� ���� 
* ���		: �Լ��� �̸� �ۼ�
* ����		: ȣ��� �Լ� ��ġ
* 
* void Upgrade(){}
* 
* 1. void		: ��ȯ�� B ���� ����� Ÿ���� �����Ѵ�. ��, ��ȯ���� ����. 
* 2. Upgrade	: �Լ��� �̸�.
* 3. ()			: A���� Ÿ���� �����ϴ� ��. �ƹ��͵� ������ voidŸ���̴�.
* 4. {}			: �ڵ尡 ���ǵǴ� �κ� (Body)
*/

/*
* void���� ��ȯ ���¿����� ������ �ȵǴµ�, �Ű� ������ �ش��ϴ� ������ �� �� �ִ� ����?
* Upgrade(){} ���°� ��� void�� ����Ѵ�. 
*/

#include <stdio.h>
#include <stdbool.h>

/*
* ��ȯ���� ���� -> ������ void, ������ int? 
*/

int CurrentMoney = 100;

// �������� ��ġ�� amount ������ �� �ִ��� ������
// ���ǹ����� �� �ڵ带 ������ �����Ϸ��� �Ѵ�.
// �� ������ :  ���� ���� ���� �������� ��ġ�� ���Ѵ�. ���� ������ < �������� ��ġ -> ���� ������-> false

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

void BuyItem(int price)
{
	if (IsMoneyEnough(price))	// �Ұ�ȣ �� ���� �����ϸ鼭 ���� ������� �������� Ȯ���� �� �� �ִ�.
	{
		printf("���� ����ϴ�.\n");
	}

	else
	{
		printf("���� �����ϴ�.\n");
	}
}

void Example()
{
	printf("���� ���\n");
}

int MultiplyNumber(int input)
{
	int a = 10;
	return 10 * input;
}

int main()
{
	// void ������ �Լ� : Example
	Example();

	// int ��ȯ�ϴ� �Լ�
	int result = MultiplyNumber(5);
	printf("����� ��� : %d\n", result);

	//true�� false�� ��ȯ�ϴ� �Լ�

	// IsEnoughMoney�Լ��� ����ؼ� ���� ����ϸ� ����ϴ�.
	// �ƴϸ� �����ϴٸ� ����ϱ�

	BuyItem(43);


}