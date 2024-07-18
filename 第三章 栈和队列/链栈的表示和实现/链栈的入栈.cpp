#include <iostream>
#define OK 1
typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

Status Push(LinkStack& S, SElemType e)
{
	LinkStack p = new StackNode; //生成新结点 p
	p->data = e; //将新结点数据域置为 e
	p->next = S; //将新结点插入栈顶
	S = p; //修改栈顶指针
	return OK;
}