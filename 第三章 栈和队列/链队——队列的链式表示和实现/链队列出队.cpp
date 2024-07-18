#define MAXQSIZE 100 //最大队列长度
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
	QuenePtr front; //队头指针
	QuenePtr rear; //队尾指针
}LinkQuene;

Status DeQuene(LinkQuene& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	QuenePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}
