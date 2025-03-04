#pragma once
/*
* 작성일	: 2025-03-04
* 작성자	: 박효영
* 주제	: ToyProJect 2일차
*/

/*
* #include <stdlib.h>
* #include <time.h>
* srand()	// rand seed를 지정하는 함수
* rand()
*/

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// rand 함수를 사용해 1~100 숫자 랜덤하게 출력 (정수로만)
// 30% 확률로 성공 (1~100) 70보다 크거나 같으면 성공한다. (1~100)

// A   이름(B)
// A : 반환값 
// B : 매개변수

int ReturnRandomValue();	// 1 ~ 100 

bool CheckRandomFunc(int Percent);

//int ReturnRandomInRange(int min, int max);	// 20 ~ 40