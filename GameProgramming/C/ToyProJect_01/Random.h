#pragma once
/*
* �ۼ���	: 2025-03-04
* �ۼ���	: ��ȿ��
* ����	: ToyProJect 2����
*/

/*
* #include <stdlib.h>
* #include <time.h>
* srand()	// rand seed�� �����ϴ� �Լ�
* rand()
*/

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// rand �Լ��� ����� 1~100 ���� �����ϰ� ��� (�����θ�)
// 30% Ȯ���� ���� (1~100) 70���� ũ�ų� ������ �����Ѵ�. (1~100)

// A   �̸�(B)
// A : ��ȯ�� 
// B : �Ű�����

int ReturnRandomValue();	// 1 ~ 100 

bool CheckRandomFunc(int Percent);

//int ReturnRandomInRange(int min, int max);	// 20 ~ 40