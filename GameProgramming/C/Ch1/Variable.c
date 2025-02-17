/*
작성일:	2025-02-17
작성자:	박효영
주제:	변수
*/

//	0. 환경 설정
#include <stdio.h>


int main() //프로그램 시작 지점
{
	//	player	: 닉네임(문자열)
	//	enemy	: 몬스터 이름(문자열)
	//	player's attackpower	: 플레이어의 공격력(숫자)
	//	enemy's attackpower	: 몬스터의 공격력(숫자)

	//	변수를 이용하여 한번에 player이름을 바꾸어 보자.

	//	player's attackpower 값을 8로 해주세요.
	//	컴퓨터에게 전달해야 할 정보(변수의 이름, 어떠한 종류인가 ★, 값(종류의 영향을 받는 값)


	int playerAttackPower = 30; // 프로그램에서 =은 대입하다
	int enemyAttackPower = 3;

	printf("%s와 %s가 어딘가에서 만났다.\n", "쿠키", "좀비"); // \+n 동시에 누르기
	printf("%s는 아직 %s를 눈치채지 못했다.\n", "좀비", "쿠키");
	printf("%s가 %s를 공격하여 %d 만큼 데미지를 입혔다.\n", "쿠키", "좀비", playerAttackPower);
	printf("%s와 %s가 서로 공격하여 %d와 %d 만큼의 데미지를 입혔다.\n\n", "쿠키", "좀비", playerAttackPower, enemyAttackPower);

	printf("////////////////////////////////////////////////////////////////////////////////////\n\n");

	char char1 = 'a'; 
	int int1 = 10;
	float float1 = 0.8; //%f


	printf("문자 출력: %c\n", char1);
	printf("정수 출력: %d\n", int1);
	printf("실수 출력: %f\n", float1);
	printf("문자열 출력: 좀비\n\n");

	printf("////////////////////////////////////////////////////////////////////////////////////\n\n");

	//아이템 강화 스토리

	char char2 = 'S';
	int level = 0;
	int level1 = 1;
	float float2 = 100.0f;

	printf("%c의 레벨은 %d입니다.\n", char2, level);
	printf("강화에 성공할 확률은 %.f 입니다.\n", float2);
	printf("강화를 시작합니다.\n");
	printf("강화에 성공하였습니다. %c의 레벨은 %d 입니다.\n", char2, level1);






}	//프로그램 끝나는 지점


//F5, 디버깅 버튼 누르기
//콘솔 창에 "안녕 변수" 출력해보기

	
// 1. 출력하고 싶은 내용을 작성하기
// 2. 단어, 정수, 실수, 문자열을 출력하게 하기