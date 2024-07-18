#include <iostream>
#define MAXQSIZE 100  //�����г���
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
	QuenePtr front;  //��ͷָ��
	QuenePtr rear;  //��βָ��
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
