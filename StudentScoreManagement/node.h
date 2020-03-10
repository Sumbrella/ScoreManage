#pragma once
#ifndef _NODE_H_
#define _NODE_H_

/*
   创建学生类，创建链表，
   定义链表头。
*/
typedef struct _STUDENT
{
	char name[100];
	int score;
}Student;

typedef struct _NODE
{
	Student stu;
	_NODE* Next;
}Node;

#endif