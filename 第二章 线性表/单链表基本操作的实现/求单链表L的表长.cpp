#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

int ListLength_L(LinkList L) // ���� L ������Ԫ�ظ���
{
	LinkList p;
	p = L->next; // p ָ���һ�����
	int i = 0;
	while (p) // ����������ͳ�ƽ����
	{
		i++;
		p = p->next;
	}
	return i;
}