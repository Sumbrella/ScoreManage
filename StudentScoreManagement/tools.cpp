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
            *(p + (i)) = c;
            i++; j++;
        }
        c = getch();
    }
}

// �Ƚ����������Ƿ���ͬ
int isSame(char* a, char* b, int n)
{
    int ok = 1;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) != *(b + i))
        {
            ok = 0;
            break;
        }
    }
    return ok;
}