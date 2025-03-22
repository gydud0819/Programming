#pragma once
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "MapBoder.h"
#include "Console.h"

typedef struct _POS
{
	int playerX;
	int playerY;

}POS;

typedef struct _Player
{
	char* playerShape;
	POS;
	Exit;
	//COORD pos;
}Player;

typedef struct _ITEM
{
	char* itemShape;
	int* itemCount;
	POS;
	//COORD pos;

}Item;

typedef struct _EXIT
{
	int exitX;
	int exitY;
	POS;
	//COORD pos;
	bool exit;
}Exit;

void SetCurPosition(Player* playerptr, Item* itemptr);	//커서 이동 함수

void HideCursor();	//커서 숨기기 함수

void PlayerInputKey(Player* playerptr, Item* itemptr);

void MazeExit();	// 미로 출구 함수