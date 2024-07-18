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

// �� L �е� i ��Ԫ��֮ǰ��������Ԫ��
Status ListInsert_L(LinkList& L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j; // Ѱ�ҵ� i - 1 ����㣬p ָ�� i - 1 ���
	}
	if (!p || j > i - 1)
		return ERROR; // i ���ڱ� + 1 ����С�� 1������λ�÷Ƿ�
	LinkList s = new LNode;
	s->data = e; // �����½�� s������� s ����������Ϊ e
	s->next = p->next; // ����� s ���� L ��
	p->next = s;
	return OK;
} // ListInsert_L
