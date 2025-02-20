/*
* 작성일	: 2025-02-19
* 작성자	: 박효영
* 주제	: 연산자 실습
*/

/*
* 사칙연산	: +, - , * ,/, %
*
* 단항 연산자
* 부호 : +, -	음수, 양수	-10, +10
*
* 이항 연산자
* num1+num2
* 항이 2개여야함
*
* 삼항 연산자
* ? 1항 : = 2항 : 3항
*/

/*
* 연산자의 쓰임새
* 산술 연산자: +, - , *, /, %
* 비교 연산자: > , <, ==
* 비트 연산자: (data type)을 배울 때 쓸 예정
* 관계 연산자: (or, and ||, &&)
*
*
*/
/*
* 비교 연산자 결과 : 참(true) 1, 거짓(false) 0
* 1, 0 : 1 + 0 = 1;
*/


/*
* 
* 시스템 파일
* "" 커스텀 파일 (개발자가 직접 만든 파일을 가져오겠다)
* 
* 
* #include	<>	1. 꺽새로 가져오기
* #include	""	2. 큰 따옴표로 가져오기
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	//사칙연산 + 나머지

	printf("연산자 실습\n\n");

	// 변수의 선언 초기화

	int num1 = 10;
	int num2 = 3;

	//덧셈
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	//뺄셈
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	//곱셈
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	//나누기
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	//나머지
	printf("%d %% %d = %d\n\n", num1, num2, num1 % num2); //%를 2개 써야함

	printf("-------------------------------------------------------------------\n\n");

	printf("실습 2 \n\n");

	printf("비교 결과 num1 > num2 : %d\n", num1 > num2); // 참 == true

	printf("비교 결과 num1 < num2 : %d\n\n", num1 < num2); // 거짓 == false


	printf("-------------------------------------------------------------------\n\n");

	printf("실습 3: 삼항 연산자\n\n");

	bool isTrue = true;	//0 또는 1의 결과값을 가진다
	bool isFalse = false;

	int result1 = num1 < num2;

	printf("삼항 연산자 결과 출력 : %s\n", result1 ? "true" : "false");
	printf("삼항 연산자 결과 출력 : %d\n\n", result1 ? 1 : 0);

	printf("-------------------------------------------------------------------\n\n");

	printf("실습 4: 관계 연산자 \n\n");


	//	!num2 : num2가 아니다 (!는 부정)	fasle -> true // true -> false

	printf("관게 연산자 : %d\n", (num1 == num2) || (num1 < num2));	//num1 != num2 두 수가 다를 때
	printf("관게 연산자 : %d\n\n", (num1 != num2) && (num1 > num2));	//num1 != num2 두 수가 다를 때

	printf("-------------------------------------------------------------------\n\n");

	printf("실습 5 : 복합 연산자 \n\n");

	int num3 = 2;
	int num4 = 5;
	num3 += num4;		//num3 <- 2 + 5 = 7


	//T = T + A
	//T += A

	printf("num3 + num4의 값 : %d\n\n", num3);

	printf("-------------------------------------------------------------------\n\n");

	printf("실습 6 : 후위 연산자, 전위 연산자\n\n");

	//	전위 연산자 : 문장을 먼저 처리한 후에 연산을 한다.
	//	num3의 값 : 2 출력 -> num3++ : num3 += 1;

	//	후위 연산자 : 연산된 결과를 문장에 대입한다.
	//	num4 += 1; -> printf 문장을 처리한다.

	printf("num3의 값 : %d\n", num3++);
	printf("num3의 값 : %d\n", num3);
	printf("num4의 값 : %d\n", ++num4);
	printf("num4의 값 : %d\n\n", num4);

	//	|, &, <<, >> '비트' <- 나중에 배울 예정

	printf("-------------------------------------------------------------------\n\n");

	//게임 스토리1

	//무기를 강화하는데
	//n강일 때의 무기, n+1 무기의 정보를 화면에 출력하는 스토리를 작성해보기

	//조건
	//0강 - 기본 공격력 = 5;
	//1강 - 강화된 공격력 = 7;
	
	//AP = BP + WL * GP; 총공 = 기본 공격력 + 무기 레벨 * 성장 계수

	

	int baseattack = 10;
	int weaponLv = 1;
	int weight = 2;

	int attackpower = baseattack + weaponLv * weight;
	
	printf("무기의 레벨 : %d, 무기의 공격력 : %d\n", ++weaponLv, attackpower);

	attackpower = baseattack + weaponLv * weight;
	printf("무기의 레벨 : %d, 무기의 공격력 : %d\n\n", weaponLv++, attackpower);

	printf("-------------------------------------------------------------------\n\n");

		
	//게임 스토리2
	
	// 아이템 인벤토리 -> slot. 기타 아이템 수집용 stack x 갯수
	// slot의 최대 갯수 : 변수
	// stack의 최대 갯수 : 변수
	// A 아이템을 n개 획득, B 아이템 m개 획득
	//현재 인벤토리의 갯수가 가득찼는지 안찼는지 표현하는 결과를 표현해보기 

	// 3항 연산자 이용해서 해보기

	int maxInventorySlot = 10;
	int AStackCount = 200;
	int BStackCount = 200;
	int ADrop = 555;
	int BDrop = 9999;

	printf("1시간 동안 사냥을 해서 아이템을 획득을 했다.\n");
	printf("A아이템 : %d개, B아이템 : %d개를 획득했다.\n", ADrop, BDrop);

	// 나머지

	int AInventoryCount = (ADrop % AStackCount) == 0 ? (ADrop / AStackCount) : (ADrop / AStackCount) + 1;
	int BInventoryCount = (BDrop % BStackCount) == 0 ? (BDrop / BStackCount) : (BDrop / BStackCount) + 1;

	printf("A의 갯수 : %d개, B의 갯수 : %d개\n", AInventoryCount, BInventoryCount);
	printf("결과 : %s\n", maxInventorySlot <= (AInventoryCount + BInventoryCount) ? "가득참" : "가득안참");
}
