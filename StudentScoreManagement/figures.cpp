/*
This package includes 
basic figures map and it's print methods.
*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>

#include"tools.h"
#pragma warning(disable :4996)

// �������� ����


void preStart(void)
{
	printf("��ʹ��WSAD������ϵġ����������ƶ�,\n");
	printf("ʹ�ûس����ǿո������ȷ�ϡ�\n");
	printf("������ʵ����ѧ���Ĳ��롢Ѱ�ҡ�����ɾ����ͳ�Ƶȹ���\n");
	printf("\n       ף��ʹ�����~~~~\n");
	system("pause");
}

//�հ׽���
void voidFigure(void)
{
	char void_figure_map[20][60] =
	{
		{"           ______________________________________\n"},
		{"          |      Student Score Mange System      |\n"},
		{"          |                                      |\n"},
		{"          |                                      |\n"},
		{"          |                                      |\n"},
		{"          |                                      |\n"},
		{"          |                                      |\n"},
		{"          |                                      |\n"},
		{"          |                                      |\n"},
		{"          |                                      |\n"},
		{"          |______________________________________|\n"}
	};
	for (int i = 0; i <= 10; i++)
		printf("%s", void_figure_map[i]);
}
// width 11--50   

void loadFigure(void)
{
	char load_figure_map[20][60] =
	{ 
		{"������������������������������������������"},
		{"��                   ��"},
		{"������������������������������������������"},
		{"       Loading...  "},
	};
	int x = 19; int y = 4;
	voidFigure();
	gotoxy(x, y);
	for (int i = 0; i < 4; i++)
	{
		printf("%s", load_figure_map[i]);
		gotoxy(x, y + i + 1);
	}

	// ��̬����
	gotoxy(20, 5);
	printf("[][][]");
	
	for (int a = 0; a < 3; a++)
		for (int j = 6; j + 6 < 30; j += 2)
		{
			gotoxy(20 + j % 18, 5);
			printf("[]");
			gotoxy(20 + (j - 6) % 19, 5);
			printf("  ");
			Sleep(200);
		}
}

// �����������
void passwordFigure()
{
	char password_figure_map[20][60]
	{
		{"��������������  Administrator"},
		{"�� []��  ��������"},
		{"��������������  ��             ��ck[��] "},
	};
	voidFigure();
	gotoxy(15, 4);
	for (int i = 0; i < 3; i++)
	{
		printf("%s", password_figure_map[i]);
		gotoxy(15, 4 + i + 1);
	}
	gotoxy(0, 12);
}

void welcomeFigure()
{
	char welcome_figure_map[20][60] =
	{
		{"           ______________________________________\n"},
		{"          |      Student Score Mange System      |\n"},
		{"          |              ___                     |\n"},
		{"          |             |___                     |\n"},
		{"          |   \\   /  /  |___       ___           |\n"},
		{"          |    \\ / \\/       ___   |   |          |\n"},
		{"          |                |      |___|  ___     |\n"},
		{"          |          |     |___         |___     |\n"},
		{"          |          |___       /\\  /\\  |___     |\n"},
		{"          |                    /  \\/  \\          |\n"},
		{"          |______________________________________|\n"}
	};
	voidFigure();
	int x = 11, y = 2;
	for (int i = 0; i < 38; i++)
		for (int j = 0; j < 8; j++)
		{
			gotoxy(x + i, y + j);
			printf("%c", welcome_figure_map[y + j][x + i]);
			Sleep(20);
		}
	//ʵ����˸
	for (int z = 0; z < 3; z++)
	{
		for (int i = 0; i < 38; i++)
			for (int j = 0; j < 8; j++)
			{
				gotoxy(x + i, y + j);
				printf(" ", welcome_figure_map[y + j][x + i]);
			}
		Sleep(100);

		for (int i = 0; i < 38; i++)
			for (int j = 0; j < 8; j++)
			{
				gotoxy(x + i, y + j);
				printf("%c", welcome_figure_map[y + j][x + i]);
			}
		Sleep(100);
	}
	gotoxy(0, 12);
}