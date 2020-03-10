/*
This package includes 
basic figures map and it's print methods.
*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>

#include"tools.h"
#pragma warning(disable :4996)

// ─│└┌ ┘┐


void preStart(void)
{
	printf("请使用WSAD或键盘上的↑←→进行移动,\n");
	printf("使用回车或是空格键进行确认。\n");
	printf("本程序实现了学生的插入、寻找、排序、删除、统计等功能\n");
	printf("\n       祝您使用愉快~~~~\n");
	system("pause");
}

//空白界面
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
		{"┌───────────────────┐"},
		{"│                   │"},
		{"└───────────────────┘"},
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

	// 动态加载
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

// 输入密码界面
void passwordFigure()
{
	char password_figure_map[20][60]
	{
		{"┌─────┐  Administrator"},
		{"│ []│  输入密码"},
		{"└─────┘  【             】ck[→] "},
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
			Sleep(5);
		}
	//实现闪烁
	for (int z = 0; z < 3; z++)
	{
		for (int i = 0; i < 38; i++)
			for (int j = 0; j < 8; j++)
			{
				gotoxy(x + i, y + j);
				printf(" ");
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

void menuFigure(void)
{
	char menu_figure_map[20][30] =
	{
		{"INSERT <-"},
		{"SEARCH <-"},
		{"SORT   <-"},
		{"DELETE <-"},
		{"COUNT  <-"},
		{"EXIT   <-"}
	};
	voidFigure();
	int x = 24, y = 3;
	gotoxy(x, y);
	for (int i = 0; i < 6; i++)
	{
		gotoxy(x, y + i);
		printf("%s", menu_figure_map[i]);
	}

	gotoxy(0, 12);
}

void insertFigure() 
{
	char insert_figure_map[20][60] =
	{
		{"StudentName : _________"},
		{"                       "},
		{"StudentScore: _________"},
		{"                       "},
		{"             certain <-"},
		{"             back    <-"}
	};
	int x = 18, y = 4;
	voidFigure();
	for (int i = 0; i < 6; i++)
	{
		gotoxy(x, y + i);
		printf("%s", insert_figure_map[i]);
	}
}


void searchFigure()
{
	char search_figure_map[20][60] =
	{
		{"StudentName : _________"},
		{"                       "},
		{"StudentScore: _________"},
		{"                       "},
		{"						 "},
		{"             back    <-"}
	};
	int x = 18, y = 4;
	voidFigure();
	for (int i = 0; i < 6; i++)
	{
		gotoxy(x, y + i);
		printf("%s", search_figure_map[i]);
	}
}
void sortFigure()
{
	char sort_figure_map[20][60] =
	{
		{"Sort Ascendente  <-"},
		{"Sort Descendente <-"},
	};
	voidFigure();
	int x = 20, y = 5;
	for (int i = 0; i < 2; i++)
	{
		gotoxy(x, y + i);
		printf("%s", sort_figure_map[i]);
	}

}


void deleteFigure()
{
	;
}


void countFigure()
{
	char count_figure_map[20][60] = 
	{
		{"  MaxScore  :  "},
		{"  MinScore  :  "},
		{"AverageScore:  "},
		{"   Number   :  "}
	};
	voidFigure();
	int x = 17, y = 4;
	for (int i = 0; i < 4; i++)
	{
		gotoxy(x, y + i);
		printf("%s", count_figure_map[i]);
	}
}


void confirmFigure()
{
	voidFigure();
	char confirm_figure_map[20][60] = 
	{
		{"Now you have datas →→→"},
		{"                         "},
		{"   Do you want to Save?  "},
		{"          Yes <-         "},
		{"          No  <-         "},
	};
	int x = 15, y = 3;
	for (int i = 0; i < 5; i++)
	{
		gotoxy(x, y + i);
		printf("%s", confirm_figure_map[i]);
	}
}


void saveFigure(void)
{
	char save_figure_map[20][60] =
	{
		{"┌───────────────────┐"},
		{"│                   │"},
		{"└───────────────────┘"},
		{"       Saveing...  "},
	};
	int x = 19; int y = 4;
	voidFigure();
	gotoxy(x, y);
	for (int i = 0; i < 4; i++)
	{
		printf("%s", save_figure_map[i]);
		gotoxy(x, y + i + 1);
	}

	// 动态加载
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

void byeFigure()
{
	char bye_figure_map[20][60] =
	{
		{"Good Bye !"},
		{"欢迎下次使用！"}
	};
	int x = 19; int y = 4;
	voidFigure();
	for (int i = 0; i < 2; i++)
	{
		gotoxy(x, y + i);
		printf("%s", bye_figure_map[i]);
	}

}