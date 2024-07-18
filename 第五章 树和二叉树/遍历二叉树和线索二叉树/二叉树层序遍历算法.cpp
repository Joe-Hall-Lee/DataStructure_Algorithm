#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define MAXQSIZE 100 // �����г���
typedef char QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ��
	int rear; // βָ��
}SqQuene;

Status InitQuene(SqQuene& Q)
{
	Q.base = new QElemType[MAXQSIZE]; // ��������ռ�
	// Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW); // �洢����ʧ��
	Q.front = Q.rear = 0; // ͷָ��βָ����Ϊ 0������Ϊ��
	return OK;
}

Status EnQuene(SqQuene& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR; // ����
	Q.base[Q.rear] = e;  // ��Ԫ�ؼ����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; //��βָ�� + 1
	return OK;
}

Status DeQuene(SqQuene& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR; // �ӿ�
	e = Q.base[Q.front]; // �����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE; // ��ͷָ�� + 1
	return OK;
}

Status QueneEmpty(SqQuene& Q)
{
	if (Q.rear == Q.front)
		return TRUE;
	else
		return FALSE;
}
typedef char TElemType;

typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild;  // ���Һ���ָ��
}BiNode, * BiTree;

void LevelOrder(BiNode* b)
{
	BiNode* p;
	SqQuene qu;
	InitQuene(qu); // ��ʼ������
	EnQuene(qu, b->data); // �����ָ��������
	while (!QueneEmpty(qu)) // �Ӳ�Ϊ�գ���ѭ��
	{
		DeQuene(qu, p->data);  // ���ӽ�� p
		cout << p->data;  // ���ʽ�� p
		if (p->lchild != NULL)
			EnQuene(qu, p->lchild->data); // ������ʱ�������
		if (p->rchild != NULL)
			EnQuene(qu, p->rchild->data); // ���Һ���ʱ�������
	}
}
