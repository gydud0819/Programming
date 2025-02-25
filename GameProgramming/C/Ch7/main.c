/*
* 작성일	: 2025-02-25
* 작성자	: 박효영
* 주제	: 코드의 흐름 제어 - 반복문	
*/

/*
* 반복문
* - 1+1+1+1+1 => 1 x 5
* 
* for, while
* 
* for문
* for(int i = 0; i < 10; i++)
* 
* // 조건에는 참, 거짓 (true, false)
* // 조건이 참일 때만 반복문을  실행하고 거짓일 때는 반복문을 벗어난다.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("반복문 예제1\n\n");
	// A이름의 아이템을 획득한 개수를 알고싶을 때
	int Acount = 0;
	printf("A 아이템의 개수 : %d개\n", Acount);

	// 아이템을 1개 획득했다.

	// 중단점을 통해 어떻게 실행되는지 직접 확인하면서 이해할 수 있다.
	for (int i = 0; i < 10; i++)
	{
		Acount = Acount +1;
	}
	
	printf("A 아이템의 개수 : %d개\n\n", Acount);

	printf("for 반복문 예제2\n");

	int Bcount = 0;

	for (int i = 0; i < 10; i++)
	{
		Bcount = Bcount + i;
	}
	printf("B 아이템의 개수 : %d개\n\n", Bcount);

	printf("for 반복문 예제3\n");

	for (int x = 10; x > 0; x--)
	{
		printf("현재 B의 값: %d\n", x);
	}

	// 게임의 이야기를 입혀서 반복문 표현해보기

	//break <- 

	for (; ; )
	{
		// 무기 강화하는 step
		
		// 1. 무기의 stat 표현해주는 단계
		// 무기의 이름
		printf("무기의 이름 : %s\n", "막대사탕");
		// 무기의 레벨
		int weopLevel = 5;
		// 기본 공격력, 가중치
		int basicPower = 3;
		int growLevel = 10;
		// 무기의 공격력 = 기본 공격력 + 레벨 * 가중치
		int AttakPower = basicPower + weopLevel * growLevel;

		printf("강화를 시작합니다.\n");

		printf("강화된 무기의 공격력은 %d 입니다.\n", AttakPower);

	
		// 2. 강화를 진행하는 단계
		//강화를 진행할 것인가? 그만할 것인가?
		printf("강화를 진행하시겠습니까? (Y/N)\n");

		char check = ' ';
		scanf_s("%c", &check,1);

		if (check == 'Y')
		{
			printf("강화를 진행합니다.\n");
			
		}
		else if (check == 'N')
		{
			printf("강화를 종료합니다.\n");
			
		}
		else
		{
			printf("잘못된 값을 입력하였습니다.\n");

			char another = ' ';
			scanf_s("%c", &another,1);
			while(getchar() != '\n')

			if (another == 'Y')
			{
				printf("강화를 진행합니다.\n");
			}
			else if (another == 'N')
			{
				printf("강화를 종료합니다.\n");
			}
			else
			{
				printf("프로그램이 종료되었습니다.\n");
			}
		}

		break;
	}

 /*
 * 반복문을 사용한다.
 * for반복문을 사용한다.
 * n번 반복하는 코드를 쉽게 표현하기 위해서
 * 
 * 몇번 반복해야 할지 잘 모르겠는 내용이 있을 수 있다.
 * ex) 잘못된 값을 입력했을 때 정확한 값을 요구하는 코드
 */

	// while 반복문
	// 무한 반복문 (중괄호 속 코드가 참이면 무한반복한다)

	int xi = 0;

	while (xi<10) //	( ) 조건식 : 조건이 true일 때 { } 실행, 조건이 false이면 반복문을 종료한다.
	{
		xi++;	// while을 탈출하기 위한 조건문

		printf("xi의 값 : %d\n", xi);
	}

	//for반복문을 쓰면 좋을까? while반복문을 쓰면 좋을까?

	// 반복횟수가 정해져있으면 for반복문이 작성하기가 편하다.

	// 반복횟수가 몇 번 반복해야할지 잘 모르겠을 때 -> while반복문

	// n번 반복할 코드를 작성하고 싶을때


	// 2만큼 증가하는 변수 numA가 있다.
	// 이 numA가 10보다 크거나 같을 때 종료되기를 원한다.
	// numA 숫자가 10보다 커지기 위해 몇 번 반복했는지 알고 싶다.
	// 반복한 결가 정수형 countA로 출력하기

	int numA = 0;
	int CountA = 0;
	printf("numA의 값을 입력해주세요(단, 10보다 작아야 합니다.)\n");
	scanf_s("%d", &numA);	// numA의 값이 정해진다.

	// while문 표현법
	/*while (true)
	{
		numA += 2;
		CountA++;

		if (numA > 10)
		{
			printf("반복한 횟수 : %d\n", CountA);
			printf("현재 값 : %d\n", numA);
			break;
		}

	}*/

	// 쉽게 표현하는 방법
	while (numA <= 10)
	{
		numA += 2;
		CountA++;
	}

	printf("반복한 횟수 : %d\n", CountA);
	printf("현재 값 : %d\n", numA);

	// for반복문 표현 <-> while반본묵 표현하기

	//실습예제 1
	//1부터 10 사이의 값중 짝수만 출력하기
	// 현재 값 : 2, 3, 4, 5...

	printf("실습 예제1\n");

	int num = 0;
	int sum = 0;

	for (int i = 0; i < 10; i+=2)
	{
		num += 2;
		sum++;
	}
	printf("짝수 : %d\n", num);


	// 실습을 다했을 경우 Y, N , 다시 입력하세요 <- Y,N 입력할 때 까지 무한히 반복되는 코드 작성하기

	// while문 사용해서 Y, N을 입력할 때까지 반복하는 코드 작성하기

	// scanf_s();
	// while(getchar() != '\n'); 사용하기
	
 }