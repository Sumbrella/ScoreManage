#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

#include"node.h"
#include"tools.h"
#include"figures.h"
#include"process.h"


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
				break;
			case 2:
				break;
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

}