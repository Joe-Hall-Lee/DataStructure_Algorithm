#include <iostream>
#define OK 1;
typedef int SElemType;
typedef struct
{
	SElemType* base; // 栈底指针
	SElemType* top; // 栈顶指针
	int stacksize; // 栈可用最大容量
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