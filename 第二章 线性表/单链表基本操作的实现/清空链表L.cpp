#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

Status ClearList(LinkList& L) // �� L ����Ϊ�ձ�
{
	Lnode* p, * q; // �� LinkList p, q
	p = L->next;
	while (p) // û����β
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL; // ͷ���ָ����Ϊ��
	return OK;
}