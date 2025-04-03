#pragma once
#include "Console.h"

/*
* 구조체를 정의할 때 어떤 것을 먼저 선언해야하는지 잘 생각해야한다. 그렇지 않으면 먼저 선언한 구조체가 인식을 하지 못하는 경우가 발생하여 오류가 날 수 있다. 
*/

typedef struct _POS		// 위치 구조체
{
	int posX;
	int posY;
}Pos;

typedef struct _EXIT	// 출구 구조체
{
	Pos exitPos;
	bool exit;
}Exit;

typedef struct _ITEM	// 아이템 구조체
{
	char* itemShape;
	Exit itemExit;

}Item;

typedef struct _PLAYER	// 플레이어 구조체
{
	char* playerShape;
	Pos playerPos;
	BOOL mazeExit;
	int itemCount;
}Player;




void MovePlayer(Player* playerptr, const Exit* exitptr);
void PlayerInputKey(Player* playerptr, const Exit* exitptr);
