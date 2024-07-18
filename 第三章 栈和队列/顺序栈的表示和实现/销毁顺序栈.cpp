#include <iostream>
#define OK 1;
typedef int SElemType;
typedef struct
{
	SElemType* base; // ջ��ָ��
	SElemType* top; // ջ��ָ��
	int stacksize; // ջ�����������
}SqStack;

typedef int Status;
Status DestroyStack(SqStack& S)
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}

	return OK;
}