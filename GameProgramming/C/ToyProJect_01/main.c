/*
* �ۼ���	: 2025-03-03
* �ۼ���	: ��ȿ��
* ����	: ������ ���� �����
*/

#include <stdio.h>
#include <stdbool.h>
#include "Intro.h"

/*
* ����Ű ���� (���־� ��Ʃ���)
*
* f12 : �Լ��� �̸� ���콺 ��Ŭ�� - ���Ƿ� �̵� ����Ű
* �̸��� ���� Ŭ�� - f12 ������
*
* ctrl + '-' : ���� ȭ������ ���ư���
*
* ctrl + z : �����α�
*
* ctrl + k, s : �ڵ� ���α�
*
* ctrl + K + d : �ڵ� ���� ���� - �鿩���⸦ default ������� �����ش�.
*
* ctrl + k + c : ���� �ּ�
*
* ctrl + k + u : ���� �ּ� ����
*
*/

/*
* ���� ���� ����
* ������ �ý����� �����ߴ�
* 
* RPG - ���Ⱝȭ �ý���
* - ���ǹ�, ������ �Է��� ������ �� �ְ� �ߴ�. -> if���ǹ� Ȱ��, printf, scanf_s	=> 1����
* - Upgrade, Currency, Random												=> ��� �и�
* - ���� ���� : ��ȭ, Ȯ��, ������ Ŭ���� ����	=> extern�� ����Ͽ� ��ü�� �ʿ��� ������ �������� ����ߴ�.
* 
* ������ �߰��� ��
* Ű���� �Է¿� ���� ��ȭ�ϴ°� ������ ���� �� ����.
* �ܼ� â���� "�÷��̾�" Player - NPC
* Player - InPutKey�� �̿��ؼ� �����̴� ��
* 
* �̵� + ��ȭ �ý��� ���� << - C��ȭ�� �� ��
*
*/

#include "Random.h"

int main()
{
	IntroMenu();

	/*for (int i = 0; i < 10; i++)
	{
		int randomNumber = ReturnRandomValue();
		int randomRange = ReturnRandomInRange(20, 40);
		printf("���� ���� %d : %d\n", i+1, randomRange);
	}*/
}