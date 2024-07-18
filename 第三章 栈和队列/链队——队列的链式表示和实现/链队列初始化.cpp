#include <iostream>
#define MAXQSIZE 100 //最大队列长度
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
	QuenePtr front; //队头指针
	QuenePtr rear; //队尾指针
}LinkQuene;

Status InitQuene(LinkQuene& Q)
{
	Q.front = Q.rear = new QNode;
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}