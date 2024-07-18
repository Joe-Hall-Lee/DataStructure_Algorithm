#include <stdio.h>
#define OK 1

typedef int TElemType;
typedef int Status;
typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild; // 左右孩子指针
}BiNode, * BiTree;

void visit(BiTree T)
{
	printf("%d", T->data);
}

Status PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; // 空二叉树
	else
	{

		PostOrderTraverse(T->lchild); // 递归遍历左子树
		PostOrderTraverse(T->rchild); // 递归遍历右子树
		visit(T); // 访问根结点
	}
}
