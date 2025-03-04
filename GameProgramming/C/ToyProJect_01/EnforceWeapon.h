#pragma once

// money system header (강화에 필요한 재화) 구현
// Upgrade System header (무기 강화) 구현

#include <stdio.h>		// 입출력 함수를 포함하는 헤더
#include <stdbool.h>	// bool 타입 추가
#include <conio.h>		// _getch() 입력 버퍼 없이 입출력 함수를 포함하는 헤더
#include <Windows.h>	// system("cls"); 윈도우 콘솔 함수가 포함되어 있는 헤더
//#include <stdlib.h>	// rand() 함수 사용하기 위한 헤더
//#include <time.h>		// time() 함수 사용하기 위한 헤더
#include "Random.h"		// 업그레이드 랜덤 강화를 위한 사용자 지정 헤더
#include "Currency.h"	// 재화 사용 함수를 위한 사용자 지정 헤더

void ShowMenu();		// 1. 강화한다. 2. 현재 상태를 보여준다.

// ShowMenu 에 따른 실행 함수

void Upgrade();
void ShowStatus();

// 게임의 종료 조건
// 목표를 달성했는가?			- success 성공

bool IsGameClear();			// 무기의 레벨

// 재화를 모두 소진했는가?	- fail 실패

// 전역 변수

// extern 전역 변수가 어딘가에 존재한다.
// Play.c 전역 변수를 정의.

extern int CurrentLevel;
extern int TargetLevel;
extern bool IsClear;
