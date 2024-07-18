#include <iostream>
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;  // 左右孩子指针
}BiTNode, * BiTree;

int Copy(BiTree T, BiTree& NewT)
{
	if (T == NULL)
	{
		// 如果是空树返回 0
		NewT = NULL;
		return 0;
	}
	else
	{
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}
