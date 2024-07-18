#include <iostream>
#define MAXQSIZE 100  //最大队列长度
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
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

Status GetHead(LinkQuene Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.front->next->data;
	return OK;
}
