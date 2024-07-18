#include <iostream>
typedef int TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild; // ×óÓÒº¢×ÓÖ¸Õë
}BiTNode, * BiTree;

int NodeCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
.