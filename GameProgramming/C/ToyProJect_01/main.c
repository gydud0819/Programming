/*
* 작성일	: 2025-03-03
* 작성자	: 박효영
* 주제	: 간단한 게임 만들기
*/

#include <stdio.h>
#include <stdbool.h>
#include "Intro.h"

/*
* 단축키 정리 (비주얼 스튜디오)
*
* f12 : 함수의 이름 마우스 우클릭 - 정의로 이동 단축키
* 이름을 더블 클릭 - f12 누르기
*
* ctrl + '-' : 이전 화면으로 돌아가기
*
* ctrl + z : 오려두기
*
* ctrl + k, s : 코드 감싸기
*
* ctrl + K + d : 자동 서식 맞춤 - 들여쓰기를 default 방식으로 맞춰준다.
*
* ctrl + k + c : 범위 주석
*
* ctrl + k + u : 범위 주석 해제
*
*/

/*
* 오늘 배운거 정리
* 간단한 시스템을 구현했다
* 
* RPG - 무기강화 시스템
* - 조건문, 유저의 입력을 선택할 수 있게 했다. -> if조건문 활용, printf, scanf_s	=> 1주차
* - Upgrade, Currency, Random												=> 기능 분리
* - 전역 변수 : 재화, 확률, 게임의 클리어 여부	=> extern을 사용하여 전체에 필요한 변수를 공통으로 사용했다.
* 
* 앞으로 추가할 것
* 키보드 입력에 따라서 변화하는게 있으면 좋을 것 같다.
* 콘솔 창에서 "플레이어" Player - NPC
* Player - InPutKey를 이용해서 움직이는 것
* 
* 이동 + 강화 시스템 연동 << - C심화때 할 것
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
		printf("랜덤 숫자 %d : %d\n", i+1, randomRange);
	}*/
}