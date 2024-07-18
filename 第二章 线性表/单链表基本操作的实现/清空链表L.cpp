#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

Status ClearList(LinkList& L) // 将 L 重置为空表
{
	Lnode* p, * q; // 或 LinkList p, q
	p = L->next;
	while (p) // 没到表尾
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL; // 头结点指针域为空
	return OK;
}