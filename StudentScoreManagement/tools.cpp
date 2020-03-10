#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

#include "node.h"

#pragma warning(disable:4996)

/*
	��װ��һЩ������Ƶ�����õĺ���
*/

Node* g_Head = NULL;

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

// �õ��û������룬ת��Ϊw��d
void getKeyboard(char* keyboard)
{
    char ch1, ch2;
    ch1 = getch();
    if (ch1 == 'w' || ch1 == 'W')      ch1 = 'w';
    else if (ch1 == 's' || ch1 == 'S') ch1 = 's';
    else if (ch1 == -32)
    {
        ch2 = getch();
        if (ch2 == 72) ch1 = 'w';
        else if (ch2 == 80) ch1 = 's';
    }
    *keyboard = ch1;
}

// ָ���ƶ�����
/*
::param: �����ֵͼ
::return:����ȷ�ϱ��
*/
int mapMove(int keyboard_map[10][5], int n)
{
    char keyboard = '|';
    char* p_keyboard = &keyboard;
    //i ����λ��
    int i = 0;
    gotoxy(keyboard_map[i][0], keyboard_map[i][1]);
    while (keyboard != '\r' && keyboard != ' ')
    {
        if (keyboard == 'w')      i--;
        else if (keyboard == 's') i++;

        // ʵ��ָ�����·�ת
        if (i >= n) i -= n;
        if (i < 0) i += n;
        gotoxy(keyboard_map[i][0], keyboard_map[i][1]);
        getKeyboard(p_keyboard);
    }
    return i;
}


//ʵ������ѧ��
void inputStudent(char name[100], int score)
{
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->Next = NULL;
    memset(pNewNode->stu.name, '\0', sizeof(pNewNode->stu.name));
    memcpy(pNewNode->stu.name, name, sizeof(name));
    pNewNode->stu.score = score;

    if (g_Head == NULL)
        g_Head = pNewNode;
    else
    {
        pNewNode->Next = g_Head;
        g_Head = pNewNode;
    }
}


// Ѱ��ѧ��
bool searchStudent(char* name, int* score)
{
    Node* p = NULL;
    bool ok = false;
    for (p = g_Head; p != NULL; p = p->Next)
    {
        if (isSame(p->stu.name, name, strlen(name)))
        {
            *score = p->stu.score;
            ok = true;
        }
    }
    return ok;
}
