#include <iostream>
#define OK 1
typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

Status InitStack(LinkStack& S)  // 构造一个空栈，栈顶指针置为空
{
	S = NULL;
	return OK;
}