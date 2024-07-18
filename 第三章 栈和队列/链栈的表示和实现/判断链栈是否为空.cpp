#include <iostream>
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

Status StackEmpty(LinkStack S)
{
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}