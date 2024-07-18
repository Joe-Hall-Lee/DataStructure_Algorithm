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
	// �����Ա� L �в���ֵΪ e ������Ԫ��
	// �ҵ����򷵻� L ��ֵΪ e ������Ԫ�صĵ�ַ������ʧ�ܷ��� NULL
	LinkList p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}
