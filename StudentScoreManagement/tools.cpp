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

void getPassword(char* p)
{
    int j = 0;
    char c;
    c = getch();
    for (int i = 0; c != ' ' && c != '\r';)
    {
        if (c == '\b')
        {
            if (j > 0 && i > 0)
            {
                if (j <= 12)
                    printf("\b \b");
                i--;
                j--;
            }
        }
        else
        {
            if (j < 12)
            {
                printf("*");
            }
            if (i < 6)
                *(p + (i)) = c;
            i++; j++;
        }
        c = getch();
    }
}