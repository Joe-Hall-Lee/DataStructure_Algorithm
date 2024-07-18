#include <iostream>
typedef int TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;  // ���Һ���ָ��
}BiTNode, * BiTree;

int LeafCount(BiTree T)
{
	if (T == NULL)
		return 0;  // ����ǿ������� 0
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;  // �����Ҷ�ӽڵ㷵�� 1
	else
		return LeafCount(T->lchild) + LeafCount(T->rchild);
}
