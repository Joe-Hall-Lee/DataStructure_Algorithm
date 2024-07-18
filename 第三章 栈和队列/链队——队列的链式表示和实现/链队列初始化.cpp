#include <iostream>
#define MAXQSIZE 100 //�����г���
#define OK 1
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode, * QuenePtr;

typedef struct
{
	QuenePtr front; //��ͷָ��
	QuenePtr rear; //��βָ��
}LinkQuene;

Status InitQuene(LinkQuene& Q)
{
	Q.front = Q.rear = new QNode;
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}