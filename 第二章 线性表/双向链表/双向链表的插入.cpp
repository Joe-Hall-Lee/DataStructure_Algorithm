#include "GetElemP_DuL.h"

int ListInsert_Dul(DuLinkList& L, int i, ElemType e) //在带头结点的双向循环链表 L 中第 i 个位置之前插入元素 e
{
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	DuLinkList s = new DuLNode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
} // ListInsert_DuL
