#include <iostream>
#define MAXQSIZE 100  //�����г���
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
	QuenePtr front;  //��ͷָ��
	QuenePtr rear;  //��βָ��
}LinkQuene;

Status GetHead(LinkQuene Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.front->next->data;
	return OK;
}
