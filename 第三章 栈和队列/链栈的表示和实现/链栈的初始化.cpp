#include <iostream>
#define OK 1
typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

Status InitStack(LinkStack& S)  // ����һ����ջ��ջ��ָ����Ϊ��
{
	S = NULL;
	return OK;
}