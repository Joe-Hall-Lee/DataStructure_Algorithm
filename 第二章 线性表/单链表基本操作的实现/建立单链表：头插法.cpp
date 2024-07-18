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
	L->next = NULL; // 先建立一个带头结点的单链表
	for (int i = n; i > 0; --i)
	{
		LinkList p = new LNode; // 生成新结点 LinkList p = (LNode*)malloc(sizeof(LNode));
		cin >> p->data; // 输入元素值 scanf(&p->data);
		p->next = L->next; // 插入到表头
		L->next = p;
	}
} // CreateList_H