#include <stdio.h>
#define OK 1

typedef int TElemType;
typedef int Status;
typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild; // ���Һ���ָ��
}BiNode, * BiTree;

void visit(BiTree T)
{
	printf("%d", T->data);
}

Status PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; // �ն�����
	else
	{
		visit(T); // ���ʸ����
		PreOrderTraverse(T->lchild); // �ݹ����������
		PreOrderTraverse(T->rchild); // �ݹ����������
	}
}
