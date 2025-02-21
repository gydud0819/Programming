/*
* 작성일	: 2025-02-21
* 작성자	: 박효영
* 주제	: 문자를 표현하는 방법, 데이터의 타입 변환(데이터 형변환)
*/


/*
* 어제거 복습
* 정수, 실수
* 정수를 표현하는 방법 - 부호비트 MSB ex) -5 = 0000 0101 -> 1111 1010 -> 1111 1011
* 2의 보수 - unsigned
* 
* 실수를 표현하는 방법 - MSB / 가수/ 지수 - 0에 가까이는 표현할 수 있지만 완벽하게 0을 표현할 수는 없음
*/

/*
* 많은 데이터형을 사용해야 한다.
* int char short long - 정수
* float double - 실수
* 
* 왜 만들었는가?
* - 편하게 사용하려고 ? 
* 
* int : 정수 + 4바이트 : 
* 각 비트들은 0, 1을 저장하고 마지막 비트는 부호를 저장한다. 비트의 개수는 32개다. 
* 
* 
*/

/*
* 문자를 저장했다. 비트값을 저장했다. 
* character 측면 해석 -> 'a'
* 정수 측면 해석 -> 97
* 
* 컴퓨터에게 숫자의 값 단어를 매핑시킨다(연결한다)
* 
* ASCII : American Standard Code for Information Insitute
*/

/*
* 정수형 데이터 4바이트 이름을 'num' 선언을 하세요. 그리고 값을 10으로 초기화 하세요.
* int num;
* num = 10;
* 
*/

/*
* literal == 문자 그대로
* literal 상수 : 
* 컴퓨터 입장에서 가장 보편적으로 많이 사용하는 타입을 변환해준다.
* 10 <- 정수 형태 int형
* 11.5 <- 실수 형태 double형
* 
* 상수 -  10
* int num;
* num = 40;
* num = 10;
* 10 = 30;
* 
* 
* 
* 심볼릭 상수 - 변수처럼 이름을 지정 해줄 수 있다.
* int PI = 3.14
*/

/*
* 형변환 
* 자동 - 묵시적 변환
* 수동 - 명시적 변환 
* 
* 명시적 변환하는 방법
* float fnum10 = 0.1f;
* int tempInt = (int)fnum10; 
*/

/*
* 다음 시간에 배울거
* 반복문
*/

#include <stdio.h>


int main()
{
	int num1 = 10;
	char num2 = 1;
	short num3 = 5;
	long num4 = 2;

	printf("정수 데이터의 크기 비교\n\n");

	printf("데이터의 바이트 크기 : %dbyte\n",sizeof(num1));
	printf("데이터의 바이트 크기 : %dbyte\n",sizeof(num2));
	printf("데이터의 바이트 크기 : %dbyte\n",sizeof(num3));
	printf("데이터의 바이트 크기 : %dbyte\n\n",sizeof(num4));

	float fnum1 = 0.1f;
	double fnum2 = 0.2;

	printf("---------------------------------------------\n");

	printf("실수 데이터의 크기 비교\n\n");

	printf("데이터의 바이트 크기 : %dbyte\n",sizeof(fnum1));
	printf("데이터의 바이트 크기 : %dbyte\n",sizeof(fnum2));

	printf("---------------------------------------------\n");

	printf("문자를 출력한다.\n\n"); 

	char c1 = 'Z'; // c1 : 변수 char / 'Z' = 90
	printf("값 : %c\n", c1);		//  0000 0000 
	printf("값 : %d\n\n", c1);	

	// 128개의 숫자 a~z, A~Z

	wchar_t charNum = L'가';

	printf("유니코드 값 : %d\n", charNum);

	printf("---------------------------------------------\n");

	printf("심볼릭 상수 예시\n\n");

	const double PI = 3.14;
	//PI = 3.1415; // 수정안됨

	printf("값 출력 : %.4lf\n", PI);

	printf("예제 문제\n\n");

	// 원의 넓이를 구하는 공식
	// 원의 넓이 = Pi * 반지름 * 반지름;		Pir^2
	// PI을 무엇으로 해야할지 토론하여 3.14로 고정
	// 
	// 다른 사람이 원의 넓이 PI에 접근하지 못하도록 코드 작성하기

	double PI1 = 3.16;

	printf("PI는 %.2f이다.\n", PI1);

	const double PI2 = 3.14;

	printf("지금부터 PI는 %.2f이다.\n", PI2);

	printf("---------------------------------------------\n"); //강사님이 하신 거

	double radius = 5;
	double extent = radius * radius * PI;

	printf("원의 넓이 : %lf\n", extent);
	
	

	// 플레이어 구성 요소
	// 체력, 공격력
	// 사망했다. (체력<=0) -> 원래 체력으로 부활
	// 기본 체력으로 부활했다.

	printf("---------------------------------------------\n");

	const int hp = 10; // 고정 체력

	int hp2 = 0;

	printf("플레이어의 체력은 %d이다.\n", hp);

	if (hp2 <= 0)
	{
		printf("플레이어의 체력이 %d이 되어 죽었다.\n", hp2);

	}
	printf("5초 뒤에 다시 살아난 플레이어의 체력은 %d이다.\n\n", hp); // 내가 한거 


	printf("---------------------------------------------\n");

	const int REVIVEHP = 10; //강사님이 한거 
	int currentHP = REVIVEHP;

	currentHP <= 0;

	printf("플레이어가 사망하였습니다.\n");
	printf("부활하시겠습니까?\n");
	currentHP = REVIVEHP;
	printf("플레이어가 부활했습니다.\n");

	printf("---------------------------------------------\n");

	// 명시적 변환하는 방법
	float fnum10 = 0.1f;
	int tempInt = (int)fnum10;		// 0000 0000

	printf("값 : %d\n", tempInt);
	printf("값 : %f\n", (float)tempInt);

	// 묵시적 변환
	// case1. 대입 연산자를 사용할 때 두 변수의 타입이 다르면 발생한다. 

	float fnum11 = 0.1f;
	int tempInt2 = fnum10;	// 데이터 선언 및 초기화 

	printf("값 : %d\n", tempInt2);
	printf("값 : %f\n", (float)tempInt2);

	// case2. 정수의 승격에 의한 자동 형변환
	// char, short -> int로 자동 변환

	short ex1 = 15;		// 15 -> int
	short ex2 = 25;		// 25 -> int
	short ex3 = ex1 + ex2;	//15 + 25 int -> short

	// case3. 연산자의 자료 불일치 

	// 공격력 = 기본 공격력 + 레벨 * 가중치

	int baseAttack = 10;
	int level = 1;
	double weight = 0.5;
	int AP = baseAttack + level * weight;	// 10 + (1 * 0.5)
	// (double)1 * 0.5	- 자료형이 일치하지 않는다
	// 0.5
	// 정수 * 실수 - 실수 (실수로 표현)
	// 10 + 0.5
	// 10.5 
	// (int)AP = (int)(double)10.5


	// case3-2. 자료형 불일치 (정수, 실수) (정수, 실수)
	int abc = 129;			
	char ccc = abc;	//-127

	printf("값 : %d\n", ccc);
	// [] x4 <- [] x1 : [] [] [] [] x1
	// [] x4 -> [] x1 : // [1010] [010101] [101010] [] x1
	
	// 자료형을 변환할 때 데이터의 손실이 가장 적은 방향으로 변환이 된다.
	// 정수보다 실수를 우선으로 바뀐다.

	//[char -> short ->] int -> long -> float -> double 

	return 0;
}