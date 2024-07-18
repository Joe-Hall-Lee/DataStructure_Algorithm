#include <iostream>
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;  // ���Һ���ָ��
}BiTNode, * BiTree;

int Copy(BiTree T, BiTree& NewT)
{
	if (T == NULL)
	{
		// ����ǿ������� 0
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
