#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

int ListLength_L(LinkList L) // 返回 L 中数据元素个数
{
	LinkList p;
	p = L->next; // p 指向第一个结点
	int i = 0;
	while (p) // 遍历单链表，统计结点数
	{
		i++;
		p = p->next;
	}
	return i;
}