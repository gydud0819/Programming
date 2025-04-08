#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "Player.h"

#define ���� 30
#define ���� 30

#define ����2 30
#define ����2 30

int Stage1[����][���� + 1];
int Stage2[����2][����2 + 1];


/*\
* ���� �Ұ�
* 1. �� ���ΰ� ���̴� �Լ��� ������ �Լ� ���� �����ϱ� (���� �����ϱ�) - �Ϸ�
* 2. �ι�° �������� �����
* 3. ù��° ���������� ����ϸ� �ι�° ���������� �Ѿ���� �����ϱ�
* 4. ���� ���� ���� �ΰ� ����� 
*/

typedef struct _STAGEPOS		// �������� ��ġ �̵���Ű�� ����ü
{
	int x;
	int y;
}StagePos;

typedef struct _MOVESTAGE			// �������� ����ü
{
	char* name;
	char* (*stage)[����2 + 1];
	StagePos stagePos;
}MStage;

void ShowStage1(int* (*Stage)[���� + 1], COORD pos);	// �� ���ΰ� ���̴� �Լ�
void ShowClearStage1();	// �� ���ΰ� ������ �ʴ� �Լ�

void ShowStage2(int* (*Stage)[����2 + 1], COORD Nextpos);	// �ι�° �� �Լ�
void ShowClearStage2();		// �� ���ΰ� ������ �ʴ� 2��° �������� �Լ�


void ShowExit();	// �������� �� ���� �� �ⱸ�� ��Ÿ���� �Լ�

