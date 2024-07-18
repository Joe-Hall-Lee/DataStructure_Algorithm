#include <iostream>
#define MAXQSIZE 100 // �����г���
#define OK 1
typedef int QElemType;
typedef int Status;
typedef struct Qnode
{
	QElemType data;
	struct Qnode* next;
}Qnode, * QuenePtr;

typedef struct
{
	QuenePtr front; // ��ͷָ��
	QuenePtr rear; // ��βָ��
}LinkQuene;

Status DestroyQuene(LinkQuene& Q)
{
	while (Q.front)
	{
		QuenePtr p = Q.front->next;
		delete Q.front;
		Q.front = p;
	} // Q.rear = Q.front->next; delete Q.front; Q.front = Q.rear;
	return OK;
}
