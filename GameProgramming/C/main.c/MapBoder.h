#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "Player.h"

#define ���� 30
#define ���� 30

#define ����2 30
#define ����2 30



/*\
* ���� �Ұ�
* 1. �� ���ΰ� ���̴� �Լ��� ������ �Լ� ���� �����ϱ� (���� �����ϱ�) - �Ϸ�
* 2. �ι�° �������� �����
* 3. ù��° ���������� ����ϸ� �ι�° ���������� �Ѿ���� �����ϱ�
* 4. ���� ���� ���� �ΰ� ����� 
*/


void ShowStage1();		// �� ���ΰ� ���̴� �Լ�
void ShowClearStage1();	// �� ���ΰ� ������ �ʴ� �Լ�

void ShowStage2();	// �ι�° �� �Լ�

void ShowExit();	// �������� �� ���� �� �ⱸ�� ��Ÿ���� �Լ�

void ShowStageWithOffset(int offsetX, int offsetY, int (*map)[����]);