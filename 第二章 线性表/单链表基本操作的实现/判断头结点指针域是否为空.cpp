#include <stdlib.h>
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

int ListEmpty(LinkList L) // �� L Ϊ�ձ��򷵻� 1�����򷵻� 0
{
	if (L->next) // �ǿ�
		return 0;
	else
		return 1;
}