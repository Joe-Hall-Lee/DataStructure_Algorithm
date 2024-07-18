#include <iostream>
#define MAXQSIZE 100  //最大队列长度
#define OK 1
#define OVERFLOW -2
typedef int Status;
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode, * QuenePtr;

typedef struct
{
	QuenePtr front;  //队头指针
	QuenePtr rear;  //队尾指针
}LinkQuene;

Status EnQuene(LinkQuene& Q, QElemType e)
{
	QuenePtr p = new QNode;
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
