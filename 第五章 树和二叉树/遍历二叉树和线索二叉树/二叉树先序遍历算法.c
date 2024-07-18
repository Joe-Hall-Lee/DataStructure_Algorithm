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

Status PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; // 空二叉树
	else
	{
		visit(T); // 访问根结点
		PreOrderTraverse(T->lchild); // 递归遍历左子树
		PreOrderTraverse(T->rchild); // 递归遍历右子树
	}
}
