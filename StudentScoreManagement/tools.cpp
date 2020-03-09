#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

#pragma warning(disable:4996)

/*
	封装了一些程序中频繁调用的函数
*/

//坐标函数
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
