typedef int ElemType;
typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;

void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc = Lc = La; //用 La 的头结点作为 Lc 的头结点
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = pa ? pa : pb; // 插入剩余段
		delete Lb; // 释放 Lb 的头结点
	}
}
