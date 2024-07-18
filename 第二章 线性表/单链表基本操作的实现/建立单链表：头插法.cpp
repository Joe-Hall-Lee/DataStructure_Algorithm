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

void CreateList_H(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL; // �Ƚ���һ����ͷ���ĵ�����
	for (int i = n; i > 0; --i)
	{
		LinkList p = new LNode; // �����½�� LinkList p = (LNode*)malloc(sizeof(LNode));
		cin >> p->data; // ����Ԫ��ֵ scanf(&p->data);
		p->next = L->next; // ���뵽��ͷ
		L->next = p;
	}
} // CreateList_H