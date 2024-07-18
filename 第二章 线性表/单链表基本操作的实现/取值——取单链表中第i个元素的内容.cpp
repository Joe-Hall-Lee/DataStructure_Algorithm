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

Status GetElem_L(LinkList L, int i, ElemType& e) // ��ȡ���Ա� L �е�ĳ������Ԫ�ص����ݣ�ͨ������ e ����
{
	LinkList p = L->next;
	int j = 1; // ��ʼ��
	while (p && j < i) // ���ɨ�裬ֱ�� p ָ��� i ��Ԫ�ػ� p Ϊ��
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR; // �� i ��Ԫ�ز�����
	e = p->data; // ȡ�� i ��Ԫ��
	return OK;
} // GetElem_L