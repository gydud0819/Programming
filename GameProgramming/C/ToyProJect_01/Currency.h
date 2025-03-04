#pragma once

extern int CurrentMoney;
extern int UpgradeCost;
extern bool IsFail;			//Play.c에 있는 전역변수를 참조했다.

bool CanUpgrade(int Cost);	//Cost랑 CurrentMoney랑 비교