/*
* 작성일	: 2025-02-27
* 작성자	: 박효영
* 주제	: 지역변수와 전역변수
*/

/*
* 업그레이드 시스템
* menu // 1번, 2번, 강화 종료
*/
#include "lecture.h"
#include "Upgrade.h"
#include "Curreny.h"
#include "main.h"

int number = 1; // 전역 변수 

int CurrentMoney = 1000;	// 현재 갖고 있는 재화

// 함수의 기능 : 내가 가진 돈의 정보를 알려줘

void ShowInfo()
{

	printf("현재 가진 돈 : %d$\n", CurrentMoney);
	printf("캐릭터의 정보 : %s\n\n", "모험가");

	WaitInputKey();
}

void WaitInputKey()
{
	printf("창을 닫으려면 아무 키를 눌러주세요.\n");
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