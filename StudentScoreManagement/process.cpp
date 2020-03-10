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

extern Node* g_Head;

void _menu(int* option);
void _insert(void);
void _search(void);
void _sort(void);
void _count(void);
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
				_insert(); break;
			case 2:
				_search(); break;
			case 3:
				_sort(); break;
			case 4:
				break;
			case 5:
				_count(); break;
			case 6:
				_quit(); return;
		}
		gotoxy(0, 12);
	}
}


void _menu(int *option)
{
	system("CLS");
	menuFigure();
	gotoxy(32, 3);
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
	rewind(stdin);
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
			printf("分数错误!");
			Sleep(500);
			gotoxy(32, 6);
			printf("_________");
			gotoxy(32, 6);
			
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
	option = keyboard_map[mapMove(keyboard_map, n)][2];
	if (option == 1 && ok)
	{
		inputStudent(tmp_name, tmp_score);
	}
}


void _search(void)
{
	system("ClS");
	searchFigure();

	char tmp_name[100];
	int tmp_score;
	bool is_find;

	memset(tmp_name, '\0', sizeof(tmp_name));

	gotoxy(32, 4);
	rewind(stdin);
	scanf("%[^\n]", tmp_name);

	if (tmp_name[0] != '\0')
	{
		is_find = searchStudent(tmp_name, &tmp_score);
		if (is_find)
		{
			gotoxy(32, 6);
			printf("%d", tmp_score);
		}
		if (!is_find)
		{
			gotoxy(0, 12);
			printf("No such person\n");
			system("pause");
		}
	}
	gotoxy(40, 9);
	getch();
}

void _bubbleSortA(void);
void _bubbleSortD(void);
void _sort(void)
{
	system("CLS");
	sortFigure();
	int n = 2;
	int i,option;
	int keyboard_map[2][5] =
	{
		{39, 5, 1},
		{39, 6, 2},
	};
	i = mapMove(keyboard_map, n);
	option = keyboard_map[i][2];
	if (option == 1)
		_bubbleSortA();
	else
		_bubbleSortD();

	gotoxy(0, 12);
	printf("\t姓名\t成绩\n");
	Node* p = NULL;
	for (p = g_Head; p != NULL; p = p->Next)
		printf("\t%s\t%d\n", p->stu.name, p->stu.score);
	system("pause");
}

void swap(Node* p, Node* n);
void _bubbleSortA()
{
	Node* tail = NULL;
	Node* cur;
	Node* next;
	if (g_Head == NULL) return;
	else
	{
		while (g_Head != tail)
		{
			for (cur = g_Head, next = cur->Next; cur->Next != tail; cur = cur->Next, next= next->Next)
			{
				if (cur->stu.score > next->stu.score)
					swap(cur, next);
			}
			tail = cur;
		}
	}
}

void swap(Node* p, Node* n);
void _bubbleSortD()
{
	Node* tail = NULL;
	Node* cur;
	Node* next;
	if (g_Head == NULL) return;
	else
	{
		while (g_Head != tail)
		{
			for (cur = g_Head, next = cur->Next; cur->Next != tail; cur = cur->Next, next = next->Next)
			{
				if (cur->stu.score < next->stu.score)
					swap(cur, next);
			}
			tail = cur;
		}
	}
}

void swap(Node* p, Node* n)
{
	Node tmp;
	memset(tmp.stu.name, '\0', sizeof(tmp.stu.name));

	tmp.stu.score = p->stu.score;
	p->stu.score = n->stu.score;
	n->stu.score = tmp.stu.score;

	memcpy(tmp.stu.name, p->stu.name, sizeof(p->stu.name));
	memcpy(p->stu.name, n->stu.name, sizeof(n->stu.name));
	memcpy(n->stu.name, tmp.stu.name, sizeof(tmp.stu.name));
}


void _count()
{
	system("CLS");
	countFigure();
	// 17, 4
	int maximum, minimum, sum = 0, number = 0;
	float average;
	Node* p = g_Head;
	if (p != NULL)
	{
		maximum = minimum = p->stu.score;
		number = 1;
		sum += p->stu.score;
		for (p = g_Head->Next; p != NULL; p = p->Next)
		{
			if (p->stu.score > maximum)
				maximum = p->stu.score;
			if (p->stu.score < minimum)
				minimum = p->stu.score;
			sum += p->stu.score;
			number++;
		}
		average = sum / (float)number;
		gotoxy(32, 4);
		printf("%d", maximum);
		gotoxy(32, 5);
		printf("%d", minimum);
		gotoxy(32, 6);
		printf("%.2f", average);
		gotoxy(32, 7);
		printf("%d", number);
	}
	gotoxy(0, 12);
	system("pause");
}


void _quit(void)
{
	system("CLS");
	confirmFigure();
	// 打印已有的数据
	int i = 1;
	gotoxy(60, i);
	Node* p = g_Head;
	printf("\t姓名\t成绩\n");
	if (p != NULL)
		for (; p != NULL; p = p->Next)
		{
			gotoxy(60, ++i);
			printf("\t%s\t%d\n", p->stu.name, p->stu.score);
		}

	int keyboard_map[5][5] =
	{
		{31, 6, 1},
		{32, 6, 2}
	};
	int option;
	int n = 2;
	option = keyboard_map[mapMove(keyboard_map, n)][2];
	if (option == 1)
	{
		FILE* fp = NULL;
		fp = fopen("data.txt","w");

		fprintf(fp, "姓名,成绩,\n"); //写入行索引
		Node* p = g_Head;
		if (p != NULL)
			for (; p != NULL; p = p->Next)
				fprintf(fp, "%s,%d,\n", p->stu.name, p->stu.score);
		system("CLS");
		saveFigure();
	}
	system("ClS");
	byeFigure();
	gotoxy(0, 12);
}
