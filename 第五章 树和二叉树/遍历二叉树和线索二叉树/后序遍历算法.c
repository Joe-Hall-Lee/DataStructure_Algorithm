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

Status PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; // �ն�����
	else
	{

		PostOrderTraverse(T->lchild); // �ݹ����������
		PostOrderTraverse(T->rchild); // �ݹ����������
		visit(T); // ���ʸ����
	}
}
