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
	LinkStack p = new StackNode; //�����½�� p
	p->data = e; //���½����������Ϊ e
	p->next = S; //���½�����ջ��
	S = p; //�޸�ջ��ָ��
	return OK;
}