#pragma once
#ifndef _NODE_H_
#define _NODE_H_

/*
   ����ѧ���࣬��������
   ��������ͷ��
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