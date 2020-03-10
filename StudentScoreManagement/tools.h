#pragma once
#ifndef _TOOLS_H_
#define _TOOLS_H_

void gotoxy(int x, int y);
void getxy(int* x, int* y);
void getPassword(char* p);
int isSame(char *a, char *b, int n);
int mapMove(int keyboard[10][5], int n);
void inputStudent(char name[100], int score);
bool searchStudent(char* name, int* score);
#endif