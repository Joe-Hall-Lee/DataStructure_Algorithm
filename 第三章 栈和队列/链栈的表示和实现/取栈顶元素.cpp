#include <iostream>
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

SElemType GetTop(LinkStack S)
{
	if (S != NULL)
		return S->data;
}