#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

Lnode* LocateElem_L(LinkList L, ElemType e)
{
	// 在线性表 L 中查找值为 e 的数据元素
	// 找到，则返回 L 中值为 e 的数据元素的地址，查找失败返回 NULL
	LinkList p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}
