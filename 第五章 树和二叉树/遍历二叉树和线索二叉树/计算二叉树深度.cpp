#include <iostream>
typedef int TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild; // 左右孩子指针
}BiTNode, * BiTree;

int Depth(BiTree T)
{
	if (T == NULL)
		return 0; // 如果是空树返回 0
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);

		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}
