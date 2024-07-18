#include <iostream>
typedef int TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;  // 左右孩子指针
}BiTNode, * BiTree;

int LeafCount(BiTree T)
{
	if (T == NULL)
		return 0;  // 如果是空树返回 0
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;  // 如果是叶子节点返回 1
	else
		return LeafCount(T->lchild) + LeafCount(T->rchild);
}
