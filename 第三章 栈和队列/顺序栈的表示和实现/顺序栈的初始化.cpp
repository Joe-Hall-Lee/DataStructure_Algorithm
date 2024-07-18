#include <iostream>
#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2

typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType* base; // 栈底指针
	SElemType* top;	// 栈顶指针
	int stacksize; // 栈可用最大容量
} SqStack;

Status InitStack(SqStack& S) // 构造一个空栈
{
	S.base = new SElemType[MAXSIZE]; // 或
	// S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW); // 存储分配失败
	S.top = S.base; // 栈顶指针等于栈底指针
	S.stacksize = MAXSIZE;
	return OK;
}