#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

Status InitList_L(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}