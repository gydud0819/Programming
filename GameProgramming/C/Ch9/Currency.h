#pragma once

#include <stdio.h>
#include <stdbool.h>

// extern : �ܺο� CurrnetMoney �̸��� ���� ������ ������ �װ� ����ض� ��� �ǹ� 
// extern �� ���� ������ ���� �̸��� ������ ���� ���� �Ǿ� �浹�� �Ͼ��.
extern int CurrentMoney;

bool IsMoneyEnough(int amount);	// ��ȭ Ȯ���ϴ� �Լ�

bool UseMoney(int price);
