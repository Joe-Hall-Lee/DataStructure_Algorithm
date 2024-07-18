#include <iostream>
typedef int TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild; // ���Һ���ָ��
}BiTNode, * BiTree;

int Depth(BiTree T)
{
	if (T == NULL)
		return 0; // ����ǿ������� 0
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
