/*
작성일	: 2025-02-18
작성자	: 박효영
주제		: 변수에 대한 이해
*/

/*
	변수
	(변수) 선언
	(데이터형) + (변수의 이름); 변수의 이름이 데이터형의 성질을 갖는다. 

	(변수) 초기화: 변수에 처음으로 값을 대입하는 것

	주의할 점

	변수를 사용하려면 선언을 해야한다. 
	선어 후 초기화를 해야한다. (하지 않으면 에러가 발생)
	이미 선언한 변수에 다시 선언할 수 없다.
*/

/*
	변수의 이름 규칙
	1. 변수의 시작 이름에 숫자가 들어가면 안된다.
	2. 이름에 특수기호(특수문자)가 들어가면 안된다.
	3. 언더바, 알파벳, 숫자 
	4. 이름 사이에 공백 문자가 들어갈 수 없다. 
	5. 키워드는 이름으로 사용할 수 없다.
*/

/*
	연산자

	사칙연산				 : +, -, *, /
	나머지, 몫			 : %
	0, 1					 : bit 연산자
	a > b, a < b, a == b : 관계연산자
*/

#include <stdio.h>	//<- 기억이 안날 때 검색하기 ex. google, chat gpt, deepL (번역기)



int main()
{
	int attackPower;	//attackpower이름을 갖는 변수가 int의 성질을 갖는다.
	
	
	// 무기 공격력 공식: attackPower = 기본 공격력 + 무기의 레벨 * 성장 계수
	int basicPower = 10;
	int weaponLevel = 50;
	int growPower = 3;

	attackPower = basicPower + weaponLevel * growPower;

	//--------------------------------------------------------------------
	printf("무기의 이름: %s, 무기의 레벨: %d, 강화 성공 확률: %.1f\n\n","망치",weaponLevel, 0.9);

	printf("강화에 성공하였습니다. 무기의 공격력이 증가하였습니다.\n\n");

	
	printf("강화 후 무기의 공격력이 %d이 되었습니다.\n\n", attackPower);

	printf("--------------------------------------------------------\n\n");

	//위의 코드는 정해진 값을 계산해주는 방법

	int AP;

	int BP, WL, GP;

	printf("무기의 이름: %s, 무기의 레벨: %d, 강화 성공 확률: %.1f\n\n", "망치", weaponLevel, 0.9);

	printf("강화를 시작합니다.\n\n");

	printf("기본 공격력을 입력하세요.\n\n");
	scanf_s("%d", &BP);
	printf("무기의 레벨을 입력하세요.\n\n");
	scanf_s("%d", &WL);
	printf("성장 계수를 입력하세요.\n\n");
	scanf_s("%d", &GP);

	AP = BP + WL * GP;
	
	printf("강화된 무기 공격력은 %d 입니다.\n\n", AP);

	printf("--------------------------------------------------------\n\n");

	//위 코드는 원하는 값을 넣어서 무기 강화를 해주는 방법

	//	예제 문제
	//	사각형의 넓이를 구하는 문제를 만들어 보기

	printf("예제 문제 1: 사각형의 넓이를 출력하는 내용을 콘솔창에 출력해보세요\n\n");

	//	정수형 데이터를 선언, width(가로), hieght(세로)
	//	넓이 = 가로 * 세로

	//	사각형의 넓이를 구합니다.
	//	가로와 세로를 곱합니다.
	//	넓이는 N입니다.

	/*int squre;

	int width = 7;
	int height = 8;

	squre = width * height;

	printf("사각형의 넓이를 구합니다.\n");
	printf("가로와 세로를 곱합니다.\n");

	scanf_s("%d * %d", &width, &height);
	printf("넓이는 %d 입니다.", squre);*/

	int width, height, extent;
	

	printf("가로의 길이를 입력해주세요\n\n");
	scanf_s("%d", &width);
	printf("세로의 길이를 입력해주세요\n\n");
	scanf_s("%d", &height);


	extent = width * height;

	printf("사각형의 넓이 구하기: %d", extent);
	

	

}