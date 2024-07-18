#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

int ListEmpty(LinkList L) // 若 L 为空表，则返回 1，否则返回 0
{
	if (L->next) // 非空
		return 0;
	else
		return 1;
}