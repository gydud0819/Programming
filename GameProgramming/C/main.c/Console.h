#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

// ���, ���ڻ� ���ÿ� �����ϴ� �Լ�
void SetColor(unsigned char _BackGroundColor, unsigned char _Textcolor);

void SetCurPosition(int x, int y);

void HideCursor();

void Startscreen();		// ���� ���� ȭ�� �Լ� 