#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

// 在 L 中第 i 个元素之前插入数据元素
Status ListInsert_L(LinkList& L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j; // 寻找第 i - 1 个结点，p 指向 i - 1 结点
	}
	if (!p || j > i - 1)
		return ERROR; // i 大于表长 + 1 或者小于 1，插入位置非法
	LinkList s = new LNode;
	s->data = e; // 生成新结点 s，将结点 s 的数据域置为 e
	s->next = p->next; // 将结点 s 插入 L 中
	p->next = s;
	return OK;
} // ListInsert_L
