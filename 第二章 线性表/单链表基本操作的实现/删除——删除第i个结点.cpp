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

// 将线性表 L 中第 i 个数据元素删除
Status ListDelete_L(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	LinkList q;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j; // 寻找第 i 个结点，并令 p 指向其前驱
	}
	if (!(p->next) || j > i - 1)
		return ERROR; // 删除位置不合理
	q = p->next; // 临时保存被删结点的地址以备释放
	p->next = q->next; // 改变删除结点前驱结点的指针域
	e = q->data; // 保存删除结点的数据域
	delete q; //释 放删除结点的空间
	return OK;
} // ListDelete_L