#include <iostream>
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType* base; // 栈底指针
	SElemType* top;	// 栈顶指针
	int stacksize; // 栈可用最大容量
} SqStack;

Status StackEmpty(SqStack S) // 若栈为空，返回 TRUE；否则返回 FALSE
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}