#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

#pragma warning(disable:4996)

/*
	��װ��һЩ������Ƶ�����õĺ���
*/

//���꺯��
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
