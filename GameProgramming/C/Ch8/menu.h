#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>	// system("cls"); 화면 지우기 <-를 쓸 수 있다. 
#include <conio.h>	

/*
* 함수 (Function)
* 
* 변수의 선언
* 데이터 타입과 변수명
* 
* int variableName;
* 
* 함수의 선언
* (데이터 타입) 함수 이름();
* 리턴 타입
* 
* 호출
* 변수의 사용법 : 변수의 이름을 가져와서 사용한다.
* 함수의 사용법 : 함수의 이름을 가져와서 사용한다.
*/

/*
* 헤더 파일은 함수를 선언하여 사용한다.
*/

void SelectMenu();	// 리턴 타입 + SelectMenu() + ;