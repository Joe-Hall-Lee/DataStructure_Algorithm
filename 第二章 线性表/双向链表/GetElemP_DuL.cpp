#include "GetElemP_DuL.h"

DuLinkList GetElemP_DuL(DuLinkList L, int i)
{
	DuLinkList p = L->next;
	int j = 1; // 初始化
	while (p && j < 1) // 向后扫描，直到 p 指向第 i 个元素或 p 为空
	{
		p = p->next;
		++j;
	}
	if (!p || j > 1)
		return ERROR; // 第 i 个元素不存在

	return p;
}
