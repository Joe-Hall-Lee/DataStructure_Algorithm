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
	SElemType* base; // ջ��ָ��
	SElemType* top; // ջ��ָ��
	int stacksize; // ջ�����������
}SqStack;

typedef int TElemType;
typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild; // ���Һ���ָ��
}BiNode, * BiTree;

Status InitStack(SqStack& S) // ����һ����ջ
{
	S.base = new SElemType[MAXSIZE]; // �� S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW); //�洢����ʧ��
	S.top = S.base; //ջ��ָ�����ջ��ָ��
	S.stacksize = MAXSIZE;
	return OK;
}

Status StackEmpty(SqStack S)
{
	// ��ջΪ�գ����� TRUE�����򷵻� FALSE
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) //ջ��
		return ERROR;
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack& S, SElemType& e)
{
	// ��ջ���գ���ɾ�� S ��ջ��Ԫ�أ��� e ������ֵ�������� OK�����򷵻� ERROR
	if (S.top == S.base)  //�ȼ��� if (StackEmpty(S))
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
