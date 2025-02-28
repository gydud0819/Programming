/*
* 작성일	: 2025-02-28
* 작성자	: 박효영
* 주제	: 함수의 사용법
*/

/*
* 함수 : input 전달 output 반환(리턴)한다.
*			A			B
* A 데이터를 어딘가에 전달하여 B라는 결과값으로 반환한다.
* A, B 변수	: 전달하기 위해서 변수 선언, 반환하기 위해서 선언 
* 어딘가		: 함수의 이름 작성
* 전달		: 호출된 함수 위치
* 
* void Upgrade(){}
* 
* 1. void		: 반환값 B 변수 결과값 타입을 정의한다. 즉, 반환값이 없다. 
* 2. Upgrade	: 함수의 이름.
* 3. ()			: A변수 타입을 정의하는 곳. 아무것도 없으면 void타입이다.
* 4. {}			: 코드가 정의되는 부분 (Body)
*/

/*
* void형태 반환 형태에서는 생략이 안되는데, 매개 변수에 해당하는 생략을 할 수 있는 이유?
* Upgrade(){} 형태가 없어도 void를 써야한다. 
*/

#include <stdio.h>
#include <stdbool.h>

/*
* 반환값의 형태 -> 없으면 void, 있으면 int? 
*/

int CurrentMoney = 100;

// 아이템의 가치가 amount 구입할 수 있는지 없는지
// 조건문으로 두 코드를 나눠서 구현하려고 한다.
// 비교 연산자 :  내가 가진 돈과 아이템의 가치를 비교한다. 내가 가진돈 < 아이템의 가치 -> 돈이 부족함-> false

bool IsMoneyEnough(int amount) // 조건을 체크하는 함수
{
	return CurrentMoney >= amount ? true : false;
	// 1. 삼항 연산자 A ? B : c;
	// A 조건 : 참 -> B, 거짓 -> C
	// return true // false;

	
	/*if (currentMoney >= amount)
	{
		true;
	}
	else
	{
		false;
	}*/
}

void BuyItem(int price)
{
	if (IsMoneyEnough(price))	// 소괄호 속 값을 변경하면서 돈이 충분한지 부족한지 확인을 할 수 있다.
	{
		printf("돈이 충분하다.\n");
	}

	else
	{
		printf("돈이 부족하다.\n");
	}
}

void Example()
{
	printf("예시 출력\n");
}

int MultiplyNumber(int input)
{
	int a = 10;
	return 10 * input;
}

int main()
{
	// void 형태의 함수 : Example
	Example();

	// int 반환하는 함수
	int result = MultiplyNumber(5);
	printf("결과값 출력 : %d\n", result);

	//true와 false를 반환하는 함수

	// IsEnoughMoney함수를 사용해서 돈이 충분하면 충분하다.
	// 아니면 부족하다를 출력하기

	BuyItem(43);


}