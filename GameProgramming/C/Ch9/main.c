/*
* �ۼ���	: 2025-02-27
* �ۼ���	: ��ȿ��
* ����	: ���������� ��������
*/

/*
* ���׷��̵� �ý���
* menu // 1��, 2��, ��ȭ ����
*/
#include "lecture.h"
#include "Upgrade.h"
#include "Curreny.h"
#include "main.h"

int number = 1; // ���� ���� 

int CurrentMoney = 1000;	// ���� ���� �ִ� ��ȭ

// �Լ��� ��� : ���� ���� ���� ������ �˷���

void ShowInfo()
{

	printf("���� ���� �� : %d$\n", CurrentMoney);
	printf("ĳ������ ���� : %s\n\n", "���谡");

	WaitInputKey();
}

void WaitInputKey()
{
	printf("â�� �������� �ƹ� Ű�� �����ּ���.\n");
	_getch();
}

int main()
{
	ShowInfo();
	system("cls");
	//ShowExample();
	ShowUpgradeMenu();
	WaitInputKey();

	UseMoney(1000);
	
}