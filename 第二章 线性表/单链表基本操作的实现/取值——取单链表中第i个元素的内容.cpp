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

Status GetElem_L(LinkList L, int i, ElemType& e) // 获取线性表 L 中的某个数据元素的内容，通过变量 e 返回
{
	LinkList p = L->next;
	int j = 1; // 初始化
	while (p && j < i) // 向后扫描，直到 p 指向第 i 个元素或 p 为空
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR; // 第 i 个元素不存在
	e = p->data; // 取第 i 个元素
	return OK;
} // GetElem_L