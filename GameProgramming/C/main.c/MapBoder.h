#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "Player.h"

#define ���� 30
#define ���� 30

extern char Stage2[30][81];

/*\
* ���� �Ұ�
* 1. �� ���ΰ� ���̴� �Լ��� ������ �Լ� ���� �����ϱ� (���� �����ϱ�) - �Ϸ�
* 2. �ι�° �������� �����
* 3. ù��° ���������� ����ϸ� �ι�° ���������� �Ѿ���� �����ϱ�
* 4. ���� ���� ���� �ΰ� ����� 
*/

//typedef struct _MAP
//{
//
//}Map, Stage;


void ShowStage1();		// �� ���ΰ� ���̴� �Լ�
void ShowClearStage1();	// �� ���ΰ� ������ �ʴ� �Լ�
void ShowMap2();	// �������� �� ���� �� �ⱸ�� ��Ÿ���� �Լ�

void ShowStage2();	// �ι�° �� �Լ�

void InitStage2(Player* playerptr);