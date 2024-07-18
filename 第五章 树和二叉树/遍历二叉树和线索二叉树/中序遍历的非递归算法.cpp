#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
typedef int SElemType;
typedef int Status;
typedef struct
{
	SElemType* base; // 栈底指针
	SElemType* top; // 栈顶指针
	int stacksize; // 栈可用最大容量
}SqStack;

typedef int TElemType;
typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild; // 左右孩子指针
}BiNode, * BiTree;

Status InitStack(SqStack& S) // 构造一个空栈
{
	S.base = new SElemType[MAXSIZE]; // 或 S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW); //存储分配失败
	S.top = S.base; //栈顶指针等于栈底指针
	S.stacksize = MAXSIZE;
	return OK;
}

Status StackEmpty(SqStack S)
{
	// 若栈为空，返回 TRUE；否则返回 FALSE
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) //栈满
		return ERROR;
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack& S, SElemType& e)
{
	// 若栈不空，则删除 S 的栈顶元素，用 e 返回其值，并返回 OK；否则返回 ERROR
	if (S.top == S.base)  //等价于 if (StackEmpty(S))
		return ERROR;
	e = *--S.top;
	return OK;
}

Status InOrderTraverse(BiTree T)
{
	BiTree p = T;
	BiTree q;
	SqStack S;
	InitStack(S);
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			Push(S, p->data);
			p = p->lchild;
		}
		else
		{
			Pop(S, q->data);
			printf("%d", q->data);
			p = q->rchild;
		} // while
	}
	return OK;
}
