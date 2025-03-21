#pragma once
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "MapBoder.h"

typedef struct _POS
{
	int PlayerX;
	int playerY;

	int exitX;
	int exitY;
}POS;

typedef struct _Player
{
	char* playerShape;
	POS;
}Player;

typedef struct _ITEM
{
	char* itemShape;
	POS;

};

typedef struct _EXIT
{
	POS;
	bool Exit;
};

void SetCurPosition(int x, int y);	//Ŀ�� �̵� �Լ�

void HideCursor();	//Ŀ�� ����� �Լ�

void PlayerInputKey();