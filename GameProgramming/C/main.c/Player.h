#pragma once
#include "Console.h"

/*
* ����ü�� ������ �� � ���� ���� �����ؾ��ϴ��� �� �����ؾ��Ѵ�. �׷��� ������ ���� ������ ����ü�� �ν��� ���� ���ϴ� ��찡 �߻��Ͽ� ������ �� �� �ִ�. 
*/

typedef struct _POS		// ��ġ ����ü
{
	int posX;
	int posY;
}Pos;

typedef struct _EXIT	// �ⱸ ����ü
{
	Pos exitPos;
	bool exit;
}Exit;

typedef struct _STAGE
{
	Pos stagePos;
	bool nextStage;
}Stage;

typedef struct _ITEM	// ������ ����ü
{
	char* itemShape;
	Exit itemExit;

}Item;

typedef struct _PLAYER	// �÷��̾� ����ü
{
	char* playerShape;
	Pos playerPos;
	BOOL NextStage;
	BOOL mazeExit;
	int heartCount;
	int starCount;
	int CurrentStage;
	int prevPosX;      
	int prevPosY;      
}Player;

void MovePlayer(Player* playerptr, const Exit* exitptr);		// �÷��̾ �ܼ�â ������ �����̴� �Լ�


