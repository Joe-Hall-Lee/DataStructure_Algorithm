#pragma once
#include <iostream>
#define OK 1
#define ERROR 0

typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, * DuLinkList;

DuLinkList GetElemP_DuL(DuLinkList L, int i);
