#pragma once

// money system header (��ȭ�� �ʿ��� ��ȭ) ����
// Upgrade System header (���� ��ȭ) ����

#include <stdio.h>		// ����� �Լ��� �����ϴ� ���
#include <stdbool.h>	// bool Ÿ�� �߰�
#include <conio.h>		// _getch() �Է� ���� ���� ����� �Լ��� �����ϴ� ���
#include <Windows.h>	// system("cls"); ������ �ܼ� �Լ��� ���ԵǾ� �ִ� ���
//#include <stdlib.h>	// rand() �Լ� ����ϱ� ���� ���
//#include <time.h>		// time() �Լ� ����ϱ� ���� ���
#include "Random.h"		// ���׷��̵� ���� ��ȭ�� ���� ����� ���� ���
#include "Currency.h"	// ��ȭ ��� �Լ��� ���� ����� ���� ���

void ShowMenu();		// 1. ��ȭ�Ѵ�. 2. ���� ���¸� �����ش�.

// ShowMenu �� ���� ���� �Լ�

void Upgrade();
void ShowStatus();

// ������ ���� ����
// ��ǥ�� �޼��ߴ°�?			- success ����

bool IsGameClear();			// ������ ����

// ��ȭ�� ��� �����ߴ°�?	- fail ����

// ���� ����

// extern ���� ������ ��򰡿� �����Ѵ�.
// Play.c ���� ������ ����.

extern int CurrentLevel;
extern int TargetLevel;
extern bool IsClear;
