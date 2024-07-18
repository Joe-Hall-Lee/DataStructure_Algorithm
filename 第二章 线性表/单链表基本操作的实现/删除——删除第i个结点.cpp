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

// �����Ա� L �е� i ������Ԫ��ɾ��
Status ListDelete_L(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	LinkList q;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j; // Ѱ�ҵ� i ����㣬���� p ָ����ǰ��
	}
	if (!(p->next) || j > i - 1)
		return ERROR; // ɾ��λ�ò�����
	q = p->next; // ��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = q->next; // �ı�ɾ�����ǰ������ָ����
	e = q->data; // ����ɾ������������
	delete q; //�� ��ɾ�����Ŀռ�
	return OK;
} // ListDelete_L