#pragma once

extern int CurrentMoney;
extern int UpgradeCost;
extern bool IsFail;			//Play.c�� �ִ� ���������� �����ߴ�.

bool CanUpgrade(int Cost);	//Cost�� CurrentMoney�� ��