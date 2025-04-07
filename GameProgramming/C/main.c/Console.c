#include "Console.h"

void SetColor(unsigned char _BackGroundColor, unsigned char _Textcolor)
{
	if (_BackGroundColor > 15 || _Textcolor > 15) return;	// 1000

	unsigned short ColorNum = (_BackGroundColor << 4) | _Textcolor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

//Ŀ�� �̵� �Լ�
void SetCurPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;	// x�� x2�� �ؾ� ��ĭ�� �ȴ�.
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ŀ�� ����� �Լ�
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false; // �Ⱥ��̰�
	info.dwSize = 1; //Ŀ���� ũ�Ⱚ
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}



void ClearScreen()
{
	COORD cursorPosition = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
