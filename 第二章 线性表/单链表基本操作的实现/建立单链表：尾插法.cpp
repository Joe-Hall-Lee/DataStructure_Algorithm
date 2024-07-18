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


// 正位序输入 n 个元素的值，建立带表头结点的单链表 L
void CreateList_R(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	LinkList r = L; // 尾指针 r 指向头结点
	for (int i = 0; i < n; ++i)
	{
		LinkList p = new LNode;
		cin >> p->data; // 生成新结点，输入元素值
		p->next = NULL;
		r->next = p; // 插入到表尾
		r = p; // r 指向新的尾结点
	}
} // CreateList_R
