#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

Status DestroyList_L(LinkList& L) // ���ٵ����� L
{
	Lnode* p; // �� LinkList p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}