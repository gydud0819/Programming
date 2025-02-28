#pragma once

#include <stdio.h>
#include <stdbool.h>

// extern : 외부에 CurrnetMoney 이름이 같은 변수가 있으니 그걸 사용해라 라는 의미 
// extern 을 쓰지 않으면 같은 이름의 변수가 여러 개가 되어 충돌이 일어난다.
extern int CurrentMoney;

bool IsMoneyEnough(int amount);	// 재화 확인하는 함수

bool UseMoney(int price);
