#include <iostream>
using namespace std;
#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;


// ��λ������ n ��Ԫ�ص�ֵ����������ͷ���ĵ����� L
void CreateList_R(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	LinkList r = L; // βָ�� r ָ��ͷ���
	for (int i = 0; i < n; ++i)
	{
		LinkList p = new LNode;
		cin >> p->data; // �����½�㣬����Ԫ��ֵ
		p->next = NULL;
		r->next = p; // ���뵽��β
		r = p; // r ָ���µ�β���
	}
} // CreateList_R
