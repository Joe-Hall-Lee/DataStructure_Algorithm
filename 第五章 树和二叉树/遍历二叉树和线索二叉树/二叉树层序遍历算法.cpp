#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define MAXQSIZE 100 // 最大队列长度
typedef char QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // 初始化的动态分配存储空间
	int front; // 头指针
	int rear; // 尾指针
}SqQuene;

Status InitQuene(SqQuene& Q)
{
	Q.base = new QElemType[MAXQSIZE]; // 分配数组空间
	// Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW); // 存储分配失败
	Q.front = Q.rear = 0; // 头指针尾指针置为 0，队列为空
	return OK;
}

Status EnQuene(SqQuene& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR; // 队满
	Q.base[Q.rear] = e;  // 新元素加入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针 + 1
	return OK;
}

Status DeQuene(SqQuene& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR; // 队空
	e = Q.base[Q.front]; // 保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; // 队头指针 + 1
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
	struct BiNode* lchild, * rchild;  // 左右孩子指针
}BiNode, * BiTree;

void LevelOrder(BiNode* b)
{
	BiNode* p;
	SqQuene qu;
	InitQuene(qu); // 初始化队列
	EnQuene(qu, b->data); // 根结点指针进入队列
	while (!QueneEmpty(qu)) // 队不为空，则循环
	{
		DeQuene(qu, p->data);  // 出队结点 p
		cout << p->data;  // 访问结点 p
		if (p->lchild != NULL)
			EnQuene(qu, p->lchild->data); // 有左孩子时将其进队
		if (p->rchild != NULL)
			EnQuene(qu, p->rchild->data); // 有右孩子时将其进队
	}
}
