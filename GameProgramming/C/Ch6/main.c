/*
* 작성일	: 2025-02-24
* 작성자	: 박효영
* 주제	: 코드의 흐름과 제어 - 조건문, 반복문
*/

/*
* main 함수는 프로그램의 시작점이다.
* 코드는 위에서부터 순서대로 실행된다.
* main 함수의 마지막 중괄호를 만나면 프로그램이 종료된다.
*/

/*
* 디버깅 : 프로그램을 중단시켜서 코드를 확인하는 기능
* f9를 눌러서 중단점을생성 또는 삭제할 수 있다.
*/

/*
* 조건문 (분기문), branch
* if 문법
* if(){}	// 조건문
* () : 조건
* {} : 몸체, body
* 
* 주의할 점
* if(); {}	//세미콜론이 소괄호 뒤에 있을 때
* - 조건문에 상관없이 코드가 실행된다.
*/

/*
* if(조건1)
* 짝수 : n % 2 == 0 (어떤 수 n을 나눴을 때 0이되면 짝수)
* 홀수 : n % 2 == 1
* 
* else // if를 제외한 나머지 모든 것들
*/

/*
* 점수를 기준으로 일정 점수 이상이면 "N"등급을 매기는 시스템을 만든다.
* 점수 >= 100	: S등급이다.
* 점수 >= 90		: A등급이다.
* 점수 < 90		: F등급이다.
* 
*/

/*
* 정리
* 
* 코드의 흐름 제어 -> 조건에 따라서 특정 부분만 실행하는 방법
* if(true) {} 실행 false 실행하지 않는다
* 
* (false && true)	(false || true) // 플레이어 조작할 때 많이 쓴다.
*/

#include <stdio.h>
#include <stdlib.h>		
#include <time.h>

int main()
{
	printf("조건문 예제1\n\n");

	//int : 4바이트 크기인 공간에 정수를 저장하겠다.

	int count = 15;

	// if문 쓸때
	// 관계 연산자, 비교 연산자
	// 5 10

	// if ~ else 문
	if (count < 10)	// if문에 조건을 쓸 때 ;을 붙이지 않는다. true, false를 나타낸다.
	{
		printf("count값이 10보다 작습니다.\n");
	}
	else
	{
		printf("count값이 10보다 큽니다.\n\n");
	}

	// if ~ else if ~ else 문
	printf("예제 문제1\n\n");

	int score = 89;

	if (score >= 100)
	{
		printf("S등급, 현재 점수 : %d\n", score);
	}
	else if (score >= 90)
	{
		printf("A등급, 현재 점수 : %d\n", score);
	}
	else
	{
		printf("F등급, 현재 점수 : %d\n", score);
	}

	// 숫자 게임
	// 랜덤한 숫자 
	// 구글에 C언어 랜덤숫자 가져오는 방법 검색
	// 조건문 확인
	// 내가 입력한 숫자와 비교하기
	// 크면 -> 큽니다.

	// 숫자가 있다.
	// 조건문으로 비교해서 숫자가 큰지 작은지 비교한다.

	printf("----------------\n");

	
	// seed값

	printf("랜덤 숫자 맞추기 게임\n");
	printf("숫자의 범위 : 0 ~ 100\n");

	srand(time(NULL));

	int randomNumber = rand() % 101;

	printf("결과 값 : %d\n", randomNumber);

	int userValue = 0;

	scanf_s("%d", &userValue);

	//printf("유저의 값 : %d\n", userValue);

	if (userValue > randomNumber)
	{
		printf("목표 값보다 큽니다.\n");
	}
	else if (userValue < randomNumber)
	{
		printf("목표 값보다 작습니다.\n");
	}
	else
	{
		printf("정답입니다!\n");
	}

	// 예제 문제2
	// 숫자 맞추기 게임에서 문제를 맞춘 횟수에 따라서 랭킹을 부여해보고 싶을때

	// if ~ else if ~ else if ~ else if

	int countNumber = 1;

	if (countNumber == 1)
	{
		printf("S랭크 입니다.\n");
	}
	else if (countNumber == 2)
	{
		printf("A랭크 입니다.\n");
	}
	else if (countNumber == 3)
	{
		printf("B랭크 입니다.\n");
	}
	else if (countNumber == 4)
	{
		printf("C랭크 입니다.\n\n");
	}

	printf("----------------\n");

	//switch문

	printf("switch 예제\n\n");

	switch (countNumber)
	{
		case 1:
			printf("S랭크 입니다.\n");
			break;
		case 2:
			printf("A랭크 입니다.\n");
			break;
		case 3:
			printf("B랭크 입니다.\n");
			break;
		case 4:
			printf("C랭크 입니다.\n");
			break;
	}

	// 점수 비교 랭킹, 횟수 기준 랭킹
	// 랭킹을 부여할 수 있는 스토리 작성하기
	// 

	printf("----------------\n");
	

	printf("로또 번호 생성기\n");
	printf("로또의 최대 번호 개수 : 45\n");

	int max = 45;
	int randomNumber2 = 6;

	srand(time(NULL));

	int userNumber;
	
	for (int i = 1; i <= 6; i++)
	{
		scanf_s("%d", &userNumber);
		printf("임의의 번호 : %d", max % randomNumber2);
	}

	/*if (randomNumber2 < max)
	{
		randomNumber2 = (rand () % max) + 1;
		printf("%d\n", randomNumber2);
	}*/

	return 0;
}

// if (count < 10); => if(count < 10){}
// 세미콜론을 붙이면 코드를 다르게 인식하여 2개가 되어 실행이 된다.
