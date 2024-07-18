#include <iostream>
#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

Status Pop(LinkStack& S, SElemType& e)
{
	if (S == NULL)
		return ERROR;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return OK;
}
