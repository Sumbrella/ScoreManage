#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

#include"node.h"
#include"tools.h"
#include"figures.h"
#include"process.h"

#pragma warning(disable : 4996)

extern Node* p_Head;

void _menu(int* option);
void _insert(void);
void _search(void);
void _sort(void);
void _delete(void);
void _quit(void);
void run()
{
	// 文件预读取

	int option = 0;
	//主菜单循环
	while (1)
	{
		_menu(&option);

		switch (option) 
		{
			case 1:
				_insert();
			case 2:
				_search();
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				return;
		}
		gotoxy(0, 12);
	}
}


void _menu(int *option)
{
	system("CLS");
	menuFigure();
	int no;
	int keyboard_map[7][5] =
	{
		{32, 3, 1},
		{32, 4, 2},
		{32, 5, 3},
		{32, 6, 4},
		{32, 7, 5},
		{32, 8, 6}
	};
	no = mapMove(keyboard_map, 6);
	*option = keyboard_map[no][2];
}


void _insert(void)
{
	system("CLS");
	insertFigure();

	char tmp_name[100];
	int tmp_score;
	bool ok = false;
	
	memset(tmp_name, '\0', sizeof(tmp_name));

	gotoxy(32, 4);
	scanf("%[^\n]", tmp_name);
	if (tmp_name[0] != '\0')
	{
		gotoxy(32, 6);
		scanf("%d", &tmp_score);
		while (tmp_score > 100 || tmp_score < 0)
		{
			gotoxy(32, 6);
			printf("_________");
			gotoxy(32, 6);
			printf("请输入正确的分数！");
			Sleep(500);
			gotoxy(32, 6);
			printf("_________");
			
			scanf("%d", &tmp_score);
		}
		ok = 1;
	}
	int option;
	int n = 2;
	int keyboard_map[2][5] =
	{
		{40, 8, 1},
		{40, 9, 2},
	};
	option = mapMove(keyboard_map, n);
	if (option == 1 && ok)
	{
		inputStudent(tmp_name, tmp_score);
	}
	gotoxy(0, 12);
}


void _search(void)
{
	system("ClS");
	searchFigure();

	char tmp_name[100];
	int tmp_score;
	bool is_find;

	memset(tmp_name, '\0', sizeof(tmp_name));

	scanf("%[^\n]", tmp_name);

	if (tmp_name[0] != '\0')
	{
		is_find = searchStudent(tmp_name, &tmp_score);
	}
}

