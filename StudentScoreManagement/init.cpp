#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>

#include"init.h"
#include"tools.h"
#include"figures.h"
/*
This package include the init figures 
and theirs method.
(prestart,  loading ,  password,  welcome, predata import)
*/

void init(void)
{
	preStart();
	system("CLS");
	loadFigure();
	system("CLS");

	passwordFigure();
	// ʵ����������
	char password[6] = {'1', '2', '3', '4', '5', '6'};
	char input_password[300];
	do
	{
		gotoxy(26, 6);
		getPassword(input_password);
		if (!isSame(input_password, password, 6))
		{
			gotoxy(26, 6);
			printf("             ");
			gotoxy(26, 6);
			printf("�������");
			Sleep(200);
			gotoxy(26, 6);
			printf("             ");
			gotoxy(26, 6);
		}
		else
		{
			gotoxy(26, 6);
			printf("             ");
			gotoxy(26, 6);
			printf("������ȷ��");
			Sleep(300);
		}

	} while (!isSame(input_password, password, 6));

	system("CLS");
	welcomeFigure();

}

